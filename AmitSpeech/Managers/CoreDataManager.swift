//
//  CoreDataManager.swift
//  AmitSpeech
//
//  Created by Amit Naskar on 08/03/20.
//  Copyright © 2020 Amit Naskar. All rights reserved.
//

import Foundation
import UIKit
import CoreData

extension NSManagedObjectContext {
    
    static var current: NSManagedObjectContext {
        let appDelegate = UIApplication.shared.delegate as! AppDelegate
        return appDelegate.persistentContainer.viewContext
    }
    
   /* static var background: NSManagedObjectContext {
        let appDelegate = UIApplication.shared.delegate as! AppDelegate
        return appDelegate.persistentContainer.newBackgroundContext()
    }*/
}


class CoreDataManager {
    
    static let shared = CoreDataManager(moc: NSManagedObjectContext.current)
    
    var moc: NSManagedObjectContext
    
    private init(moc: NSManagedObjectContext) {
        self.moc = moc
    }
    
    private func fetchSpeech(_ speechId: String?, completion: (SpeechModel?, NSError?) -> Void) {
        var speechs = [SpeechModel]()
        let request: NSFetchRequest<SpeechModel> = SpeechModel.fetchRequest()
        if let speechId = speechId {
            request.predicate = NSPredicate(format: "speechModelId == %@", speechId)
        }
        do {
            speechs = try self.moc.fetch(request)
        } catch let error as NSError {
            completion(nil, error)
        }
        completion(speechs.first, nil)
    }
    
    func deleteSpeech(_ speechId: String, completion: (Bool, NSError?) -> Void) {
        fetchSpeech(speechId) { (speech, error) in
            if let speech = speech {
                self.moc.delete(speech)
                do {
                    try self.moc.save()
                    completion(true, nil)
                } catch let error as NSError {
                    completion(false, error)
                }
            }
        }
    }
    
   func updateSpeech(speechId: String, text: String, completion: (Bool, NSError?) -> Void) {
        fetchSpeech(speechId) { (speech, error) in
            if let speech = speech {
                speech.text = text
                do {
                    try self.moc.save()
                    completion(true, nil)
                } catch let error as NSError {
                    completion(false, error)
                }
            }
        }
    }
    
    func getAllSpeechs(completion: ([SpeechModel]?, NSError?) -> Void) {
        var speechs = [SpeechModel]()
        let speechRequest: NSFetchRequest<SpeechModel> = SpeechModel.fetchRequest()
        do {
            speechs = try self.moc.fetch(speechRequest)
        } catch let error as NSError {
            completion(nil, error)
        }
        completion(speechs, nil)
    }
    
    func saveSpeech(speechId: String, text: String, completion: (Bool, NSError?) -> Void) {
        let speech = SpeechModel(context: self.moc)
        speech.speechModelId = speechId
        speech.text = text
        do {
            try self.moc.save()
            completion(true, nil)
        } catch let error as NSError {
            completion(false, error)
        }
    }
    
}
