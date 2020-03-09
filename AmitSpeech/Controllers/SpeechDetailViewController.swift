//
//  SpeechDetailViewController.swift
//  AmitSpeech
//
//  Created by Amit Naskar on 08/03/20.
//  Copyright © 2020 Amit Naskar. All rights reserved.
//

import Foundation
import  UIKit

protocol SpeechDetailDelegate: class {
    func speechDetailDelegateMethod()
}

class SpeechDetailViewController: UIViewController {
    
    @IBOutlet weak var speechTextView: UITextView!
    
    weak var delegate: SpeechDetailDelegate?
    var speechVM: SpeechViewModel?
    
    static let segueIdentifier = "ShowDetail"

    override func viewDidLoad() {
        super.viewDidLoad()
        hideKeyboardWhenTappedAround()
        if let speechVM = speechVM {
            speechTextView.text = speechVM.text
        }
        speechTextView.becomeFirstResponder()
    }
    
    // MARK: - IBActions
    @IBAction func saveButtonAction(_ sender: UIBarButtonItem) {
        speechVM?.text = speechTextView.text
        speechVM?.updateSpeech(completion: { [weak self] (success) in
            if success {
                self?.delegate?.speechDetailDelegateMethod()
                self?.navigationController?.popViewController(animated: true)
            }
        })
    }
}

extension SpeechDetailViewController {
    func hideKeyboardWhenTappedAround() {
        let tap: UITapGestureRecognizer = UITapGestureRecognizer(target: self, action: #selector(SpeechDetailViewController.dismissKeyboard))
        tap.cancelsTouchesInView = false
        view.addGestureRecognizer(tap)
    }

    @objc func dismissKeyboard() {
        view.endEditing(true)
    }
}
