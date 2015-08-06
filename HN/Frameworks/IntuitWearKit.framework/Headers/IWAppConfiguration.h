//
//  IWAppConfiguration.h
//  IWApp
//
//  Created by Osmon, Cindy on 12/31/14.
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
#import <IntuitWearKit/IWearNotificationContent.h>

/*
 *  @discussion Enumeration of possible colors of the Circle Indicator
 */
//typedef NS_ENUM(NSInteger, IWRadialColor){
//    /*!
//     *  @discussion Red color
//     */
//    IWRadialColorRed,
//    /*!
//     *  @discussion Green color
//     */
//    IWRadialColorGreen,
//    /*!
//     *  @discussion Yellow color
//     */
//    IWRadialColorYellow,
//    /*!
//     *  @discussion Default color is Green
//     */
//    IWRadialColorDefault
//};

/*!
 *  External global variable that should be used to indicate the App Group name
 */
extern NSString *IWAppConfigurationApplicationGroupsPrimary;

/*!
 *  External constant representing the Key to storing and retrieving
 *  the IWearNotificationContent object shared betwen the iPhone app
 *  and the Watch App
 */
extern NSString *const IWAppConfigurationIWContentUserDefaultsKey;

/*!
 * @class IWAppConfiguration
 *
 * @discussion This class is a helper class for application configuration. 
 *             It can be used to ease access to storing and retrieving data
 *             from NSUserDefaults.
 */
@interface IWAppConfiguration : NSObject

/*!
 * @discussion Object representing all of the fields from the notification json.
 *             This data can be used to create many kinds of notifications.
 */
@property (nonatomic) IWearNotificationContent *iwContent;

/*!
 * @discussion RadialStyle contains all of the data necessary to create and draw
 *             the IWRadialCircleIndicator widget.
 */
@property (nonatomic) RadialStyle *iwRadialStyle;

/*!
 * @discussion Getter method that returns static accessor for the sharedAppConfiguration.
 *
 * @return Returns static accessor for the sharedAppConfiguration
 */
+ (IWAppConfiguration *)sharedAppConfiguration;

/*!
 *  @discussion This method converts the integer color value into its string representation.
 *
 *  @param color Integer value representing the color as defined by the IWRadialColor
 *               Enumeration. Red = 0, Green = 1, Yellow = 2
 *
 *  @return String value of the color (i.e. "Red", "Green", "Yellow"
 */
//+ (NSString *)radialColorStringFromInteger:(NSInteger)color;

@end
