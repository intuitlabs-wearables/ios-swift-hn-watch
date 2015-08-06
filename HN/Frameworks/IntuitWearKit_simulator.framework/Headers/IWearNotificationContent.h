//
//  IWearNotificationContent.h
//  IntuitWear
//
// Copyright (c) 2015 Intuit Inc.
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE.

#import <Foundation/Foundation.h>
#import <IntuitWearKit/JSONModel.h>
#import <IntuitWearKit/ListStyle.h>
#import <IntuitWearKit/BigTextStyle.h>
#import <IntuitWearKit/IWRadialIndicator.h>
#import <IntuitWearKit/Page.h>
#import <IntuitWearKit/WearableAction.h>
#import <IntuitWearKit/Action.h>

@class RadialStyle;
@class ListStyle;

/*!
 * @class IWearNotificationContent
 *
 * @description This class represents the object encapsulation of the Intuit Wear
 *  JSON schema for transferring data to wearable devices.
 */
@interface IWearNotificationContent : JSONModel  <NSCoding>

/*!
 *  The style of the notification to be delivered.
 *  Possible values are:
 *      BigTextStyle
 *      InboxStyle
 *      ListStyle
 *      RadialStyle
 */
@property (nonatomic, retain) NSString *style;

/*!
 *  Small icon to use in the notification layouts, can be resource Id or a URL
 *  on Android but must be the name of the icon on iOS.
 */
@property (nonatomic, retain) NSString<Optional> *smallIcon;

/*!
 *  Large icon to use in the notification layouts, can be resource Id or a URL
 *  on Android but must be the name of the icon on iOS.
 */
@property (nonatomic, retain) NSString<Optional> *largeIcon;

/*!
 *  Name of Background image
 */
@property (nonatomic, retain) NSString<Optional> *background;

/*!
 *  Title for the notification.
 */
@property (nonatomic, retain) NSString<Optional> *contentTitle;

/*!
 *  Body text of the notification if different then the assert text
 */
@property (nonatomic, retain) NSString<Optional> *contentText;

/*!
 *  Name of a view controller to launch when an action button is clicked
 *  or the Glance is selected.
 */
@property (nonatomic, retain) NSString<Optional> *contentIntentName;

/*!
 *  This style supports a vertically scrolling item list
 */
@property (nonatomic, retain) ListStyle<Optional> *listStyle;

/*!
 *  This style supports longer text and title than a basic notification also provides 
 *  a summary.
 */
@property (nonatomic, retain) BigTextStyle<Optional> *bigTextStyle;

/*!
 *  This style supports a radial progress chart as is used in the Apple Watch Activity App
 */
@property (nonatomic, retain) RadialStyle<Optional> *radialStyle;

/*!
 *  Actions that can be triggered by this Notification
 */
@property (nonatomic, retain) NSArray<Action, Optional> *actions;

/*!
 *  Actions that can will only be available on a wearable device, not on the handheld/phone
 */
@property (nonatomic, retain) NSArray<WearableAction, Optional> *wearableActions;

/*!
 *  Page declaration for multi-page notifications
 */
@property (nonatomic, retain) NSArray<Page, Optional> *pages;




@end
