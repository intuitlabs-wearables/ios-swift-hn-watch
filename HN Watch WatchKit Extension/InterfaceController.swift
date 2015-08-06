//
//  InterfaceController.swift
//  HN WatchKit Extension
//
//  Created by Liu, Frank on 7/20/15.
//  Copyright (c) 2015 fliu. All rights reserved.
//

import WatchKit
import Foundation

class InterfaceController: WKInterfaceController {
    
    override func awakeWithContext(context: AnyObject?) {
        super.awakeWithContext(context)
        
        // Configure interface objects here.
    }
    
    override func willActivate() {
        // This method is called when watch view controller is about to be visible to user
        super.willActivate()
    }
    
    override func didDeactivate() {
        // This method is called when watch view controller is no longer visible
        super.didDeactivate()
    }
    
    // Handles actions from PUSH
    override func handleActionWithIdentifier(identifier: String?, forRemoteNotification remoteNotification: [NSObject : AnyObject]) {
        
        if identifier == "viewUrl" {
            let payload = remoteNotification["payload"] as! NSString
            let findUrl = payload.rangeOfString("\"extras\"")
            var url = payload.substringFromIndex(findUrl.location+12)
            url = url.substringToIndex(advance(url.endIndex, -6))
            println(url)
            
            var userInfo: [NSObject : AnyObject] = NSDictionary(objects: [url], forKeys: ["url"]) as [NSObject : AnyObject]
            
            // Open URL in parent app
            WKInterfaceController.openParentApplication(userInfo, reply: nil)
            
            var url2: NSURL = NSURL(fileURLWithPath: url)!
            
            // Calls for Handoff on the iPhone
            updateUserActivity("fliu.HN.handoff", userInfo: nil, webpageURL: url2)
        }
        
    }
    
}
