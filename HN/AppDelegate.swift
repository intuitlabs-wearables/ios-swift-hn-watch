//
//  AppDelegate.swift
//  HN
//
//  Created by Liu, Frank on 6/1/15.
//  Copyright (c) 2015 fliu. All rights reserved.
//

import UIKit
import IntuitWearKit

@UIApplicationMain
class AppDelegate: UIResponder, UIApplicationDelegate {

    var window: UIWindow?

    func application(application: UIApplication, didFinishLaunchingWithOptions launchOptions: [NSObject: AnyObject]?) -> Bool {
        // Override point for customization after application launch.
        
        // Configure PUSH
        PushNotificationSDK.sharedPushManager().overrideServiceEndpoint("https://png.d2d.msg.intuit.com")
        PushNotificationSDK.sharedPushManager().senderId = "fa803a7f-a411-421f-b769-fac8ea4141ba"
        PushNotificationSDK.sharedPushManager().dryRun = true
        
        var viewAction = UIMutableUserNotificationAction()
        viewAction.identifier = "viewUrl"
        viewAction.title = "View"
        viewAction.activationMode = UIUserNotificationActivationMode.Foreground
        viewAction.destructive = false
        
        // PUSH categories
        var messageCategory = UIMutableUserNotificationCategory()
        messageCategory.identifier = "CategoryName"
        messageCategory.setActions([viewAction], forContext: UIUserNotificationActionContext.Default)
        messageCategory.setActions([viewAction], forContext: UIUserNotificationActionContext.Minimal)
        var categories = NSSet(object: messageCategory)
        
        // Push Permission Request
        UIApplication.sharedApplication().registerUserNotificationSettings(UIUserNotificationSettings(forTypes: UIUserNotificationType.Badge | UIUserNotificationType.Alert | UIUserNotificationType.Sound, categories: categories as Set<NSObject>))
        
        // Register Push
        var types:UIUserNotificationType = UIUserNotificationType.Badge |
            UIUserNotificationType.Alert |
            UIUserNotificationType.Sound
        let mySettings = UIUserNotificationSettings(forTypes: types, categories: categories as Set<NSObject>)
        UIApplication.sharedApplication().registerUserNotificationSettings(mySettings)
        
        UIApplication.sharedApplication().registerForRemoteNotifications()
        
        return true
    }
    
    // Registering device to PNG
    func application(application: UIApplication, didRegisterForRemoteNotificationsWithDeviceToken deviceToken: NSData) {
        var error: NSError?
        PushNotificationSDK.sharedPushManager().registerUser("Swift", inGroups: [], withDeviceToken: deviceToken, error: NSErrorPointer())
        if var actualError = error {
            // Handle validation error.
            println("Got a  validation error: \(actualError)")
        }
        else {
            println("No validation error, succeeded in registering user.")
            var characterSet: NSCharacterSet = NSCharacterSet( charactersInString: "<>" )
            var deviceTokenString: String = ( deviceToken.description as NSString )
                .stringByTrimmingCharactersInSet( characterSet )
                .stringByReplacingOccurrencesOfString( " ", withString: "" ) as String
            println("Got token data! (deviceToken) \(deviceTokenString)")
        }
    }
    
    func application(application: UIApplication, didFailToRegisterForRemoteNotificationsWithError error: NSError) {
        println("Failed to register for remote notifications")
    }
    
    // New callback on iOS 8, which allows the app to check the notification types supported
    func application(application: UIApplication, didRegisterUserNotificationSettings notificationSettings: UIUserNotificationSettings) {
        // user has allowed receiving user notifications of the following types
        let allowedTypes = notificationSettings.types
    }
    
    // Receive PUSH notification
    func application(application: UIApplication, didReceiveRemoteNotification userInfo: [NSObject : AnyObject]) {
        
        if (application.applicationState != UIApplicationState.Active) {
        
            let payload = userInfo["payload"] as! NSString
            let findUrl = payload.rangeOfString("\"extras\"")
            var url = payload.substringFromIndex(findUrl.location+12)
            url = url.substringToIndex(advance(url.endIndex, -6))
            
            callWebView(url)
        }
    }
    
    // Handles actions from PUSH notifications
    func application(application: UIApplication, handleActionWithIdentifier identifier: String?, forRemoteNotification userInfo: [NSObject : AnyObject], completionHandler: () -> Void) {
        
        println("handleActionWithIdentifier")
        println(userInfo)
        
        let payload = userInfo["payload"] as! NSString
        let findUrl = payload.rangeOfString("\"extras\"")
        var url = payload.substringFromIndex(findUrl.location+12)
        url = url.substringToIndex(advance(url.endIndex, -6))
        
        callWebView(url)
        
        completionHandler()
    }
    
    // Handles information coming from the Apple Watch
    func application(application: UIApplication, handleWatchKitExtensionRequest userInfo: [NSObject : AnyObject]?, reply: (([NSObject : AnyObject]!) -> Void)!) {
        print("handleWatchKitExtensionRequest")
        
        if let userInfo: AnyObject = userInfo {
            let url = userInfo["url"] as! String
            
            callWebView(url)
            
        }
    }
    
    // Renders the input url in a webview
    func callWebView(url:String) {
        let vc = PostViewController()
        vc.postLink = url
        
        var rootViewController = self.window!.rootViewController as! UINavigationController
        rootViewController.pushViewController(vc, animated: true)
    }

    func applicationWillResignActive(application: UIApplication) {
        // Sent when the application is about to move from active to inactive state. This can occur for certain types of temporary interruptions (such as an incoming phone call or SMS message) or when the user quits the application and it begins the transition to the background state.
        // Use this method to pause ongoing tasks, disable timers, and throttle down OpenGL ES frame rates. Games should use this method to pause the game.
    }

    func applicationDidEnterBackground(application: UIApplication) {
        // Use this method to release shared resources, save user data, invalidate timers, and store enough application state information to restore your application to its current state in case it is terminated later.
        // If your application supports background execution, this method is called instead of applicationWillTerminate: when the user quits.
    }

    func applicationWillEnterForeground(application: UIApplication) {
        // Called as part of the transition from the background to the inactive state; here you can undo many of the changes made on entering the background.
    }

    func applicationDidBecomeActive(application: UIApplication) {
        // Restart any tasks that were paused (or not yet started) while the application was inactive. If the application was previously in the background, optionally refresh the user interface.
    }

    func applicationWillTerminate(application: UIApplication) {
        // Called when the application is about to terminate. Save data if appropriate. See also applicationDidEnterBackground:.
    }


}

