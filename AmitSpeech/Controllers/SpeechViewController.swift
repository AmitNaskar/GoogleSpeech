//
//  SpeechViewController.swift
//  AmitSpeech
//
//  Created by Amit Naskar on 07/03/20.
//  Copyright © 2020 Amit Naskar. All rights reserved.
//

import Foundation
import AVFoundation
import googleapis

class SpeechViewController: UIViewController {
    
    @IBOutlet weak var speechTableView: UITableView!
    @IBOutlet weak var micButton: UIBarButtonItem!
    
    static let speechCellIdentifier = "SpeechTableCell"
    let tableviewTopInset = UIEdgeInsets(top: -35, left: 0, bottom: 0, right: 0)
    let SAMPLE_RATE = 16000
    var audioData: NSMutableData?
    
    var speechManager = SpeechManagerViewModel()
    
    override func viewDidLoad() {
        super.viewDidLoad()
        // Do any additional setup after loading the view.
        micButton.tintColor = .gray
        speechTableView.contentInset = tableviewTopInset
        AudioController.sharedInstance.delegate = self
        loadSpeechs()
    }
    
    // MARK: - Private Menthods
    private func loadSpeechs() {
        speechManager.fetchAllSpeechs { [weak self] (success) in
            if success {
                self?.reloadTableView()
            }
        }
    }
    private func reloadTableView() {
        DispatchQueue.main.async {
            self.speechTableView.reloadData()
        }
    }
    private func recordAudio() {
        let audioSession = AVAudioSession.sharedInstance()
        do {
            try audioSession.setCategory(AVAudioSession.Category.record)
        } catch {
            
        }
        audioData = NSMutableData()
        _ = AudioController.sharedInstance.prepare(specifiedSampleRate: SAMPLE_RATE)
        SpeechRecognitionService.sharedInstance.sampleRate = SAMPLE_RATE
        _ = AudioController.sharedInstance.start()
        speechManager.isAudioRuuning = true
        micButton.image = UIImage(systemName: "mic.fill")
        micButton.tintColor = .blue
    }
    
    private func stopAudio() {
        _ = AudioController.sharedInstance.stop()
               SpeechRecognitionService.sharedInstance.stopStreaming()
        speechManager.isAudioRuuning = false
        micButton.image = UIImage(systemName: "mic")
        micButton.tintColor = .gray
    }
    
    // MARK: - IBActions
    @IBAction func recordandStopAudio(_ sender: UIBarButtonItem) {
        if speechManager.isAudioRuuning {
            stopAudio()
        } else {
            recordAudio()
        }
    }
    
    // MARK: - Navigation
    override func prepare(for segue: UIStoryboardSegue, sender: Any?) {
        guard let detailVC = segue.destination as? SpeechDetailViewController, let index = sender as? Int else {
            return
        }
        if speechManager.isAudioRuuning {
            stopAudio()
        }
        detailVC.delegate = self
        detailVC.speechVM = speechManager.speechs[index]
    }
}

// MARK: - UITableView Delegate & Datasource
extension SpeechViewController: UITableViewDelegate, UITableViewDataSource {
    func numberOfSections(in tableView: UITableView) -> Int {
        return 1
    }
    
    func tableView(_ tableView: UITableView, numberOfRowsInSection section: Int) -> Int {
        return speechManager.speechs.count
    }
    
    func tableView(_ tableView: UITableView, cellForRowAt indexPath: IndexPath) -> UITableViewCell {
        guard let cell = tableView.dequeueReusableCell(withIdentifier: SpeechViewController.speechCellIdentifier, for: indexPath) as? SpeechTableCell else {
            fatalError("SpeechTableCell is not found")
        }
        if let speech = speechManager.speechAt(indexPath.row) {
            cell.speechLabel.text = speech.text
        }
        return cell
    }
    
    
    func tableView(_ tableView: UITableView, commit editingStyle: UITableViewCell.EditingStyle, forRowAt indexPath: IndexPath) {
        if editingStyle == .delete {
            self.speechManager.deleteSpeech(at: indexPath.row) { (success) in
                if success {
                    DispatchQueue.main.async {
                        tableView.deleteRows(at: [indexPath], with: .fade)
                    }
                }
            }
        }
    }
    
    func tableView(_ tableView: UITableView, didSelectRowAt indexPath: IndexPath) {
        performSegue(withIdentifier: SpeechDetailViewController.segueIdentifier, sender: indexPath.row)
    }
}

// MARK: - AudioControllerDelegate
extension SpeechViewController: AudioControllerDelegate {
    func processSampleData(_ data: Data) -> Void {
        guard let audioData = audioData else {
            return
        }
        
        audioData.append(data)
        
        let chunkSize : Int = Int(0.1 * Double(SAMPLE_RATE) * 2)
        
        if (audioData.length > chunkSize) {
            SpeechRecognitionService.sharedInstance.streamAudioData(audioData,
                                                                    completion:
                { [weak self] (response, error) in
                    guard let strongSelf = self else {
                        return
                    }
                    
                    if let error = error {
                        print(error.localizedDescription)
                        strongSelf.stopAudio()
                    } else if let response = response {
                        print(response)
                    
                        for result in response.resultsArray! {
                            if let result = result as? StreamingRecognitionResult {
                                if result.isFinal {
                                    //finished = true
                                }
                            }
                        }
                        if let resultArray = response.resultsArray as? [StreamingRecognitionResult] {
                            print(response)
                            for result in resultArray {
                                if result.isFinal {
                                    let text = (result.alternativesArray?.firstObject as? SpeechRecognitionAlternative)?.transcript ?? ""
                                    strongSelf.speechManager.saveSpeech(text) { (success) in
                                        if success {
                                            strongSelf.reloadTableView()
                                        }
                                    }
                                }
                            }
                        }
                    }
            })
            self.audioData = NSMutableData()
        }
    }
}

// MARK: - SpeechDetailDelegate
extension SpeechViewController: SpeechDetailDelegate {
    func speechDetailDelegateMethod() {
        loadSpeechs()
    }
}
