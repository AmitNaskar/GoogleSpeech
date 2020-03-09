//
//  SpeechManagerViewModel.swift
//  AmitSpeech
//
//  Created by Amit Naskar on 08/03/20.
//  Copyright © 2020 Amit Naskar. All rights reserved.
//

import Foundation

class SpeechManagerViewModel {
    var isAudioRuuning = false
    var speechs = [SpeechViewModel]()
}

extension SpeechManagerViewModel {
    func fetchAllSpeechs(completion: (Bool) -> Void) {
        CoreDataManager.shared.getAllSpeechs { [weak self] (speechs, error) in
            if let speechs = speechs {
                self?.speechs = speechs.compactMap(SpeechViewModel.init)
                self?.speechs.reverse()
                completion(true)
            } else {
                if let error = error {
                    print(error)
                }
                completion(false)
            }
        }
    }
    
    func deleteSpeech(at index: Int, completion: (Bool) -> Void) {
        let speechVM = speechs[index]
        CoreDataManager.shared.deleteSpeech(speechVM.speechId) { [weak self] (success, error) in
            if success {
                self?.fetchAllSpeechs { (success) in
                    if success {
                        completion(true)
                    }
                }
            } else {
                if let error = error {
                    print(error)
                }
                completion(false)
            }
        }
    }
    
    func saveSpeech(_ text: String, completion: (Bool) -> Void) {
        let date = Date()
        let speechId = date.longDateString()
        CoreDataManager.shared.saveSpeech(speechId: speechId, text: text) { [weak self] (succes, error) in
            if succes {
                self?.fetchAllSpeechs { (success) in
                    if success {
                        completion(true)
                    }
                }
            } else {
                if let error = error {
                    print(error)
                }
                completion(false)
            }
        }
    }
    
    func speechAt(_ index: Int) -> SpeechViewModel? {
        return speechs[index]
    }
}

class SpeechViewModel {
    var speechId = ""
    var text = ""
    
    init(speech: SpeechModel) {
        self.speechId = speech.speechModelId ?? ""
        self.text = speech.text ?? ""
    }
}

extension SpeechViewModel {
    func updateSpeech(completion: (Bool) -> Void) {
        CoreDataManager.shared.updateSpeech(speechId: self.speechId, text: self.text) { (succes, error) in
            if succes {
                completion(true)
            } else {
                if let error = error {
                    print(error)
                }
                completion(false)
            }
        }
    }
}

extension Date {
    public func longDateString() -> String {
        return "\(self.timeIntervalSince1970)"
    }
}
