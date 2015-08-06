//
//  IWRadialIndicator.h
//  IWApp
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
#import <IntuitWearKit/RadialStyle.h>

@import WatchKit;

/*!
 * @class IWRadialIndicator
 *
 * @discussion This class draws a radial graph of a given color with text in the
 *        middle of the circle much like you see on the Apple Watch Acitivity App.
 */
@interface IWRadialIndicator : NSObject

/*!
 * @discussion The image name of the image to be used for the Radial Indicator widget.
 */
@property (nonatomic, retain) NSString *radialColor;

/*!
 * @discussion The header text shown in the Group above the circle.
 */

@property (nonatomic, retain) NSString *radialHeaderText;

/*!
 * @discussion The number of images in the Radial circle.
 */

@property (nonatomic) NSInteger numberOfImages;

/*!
 *  Initializes the IWRadialIndicator with the data from RadialStyle.
 *
 *  @param radialStyle The RadialStyle object that contains all of the
 *                     IWRadialIndicator parameters
 *
 *  @return The IWRadialIndicator object that handles building the circle
 *         indicator and it's data
 */
- (instancetype)initWithRadialStyle:(RadialStyle *)radialStyle;

/*!
 *  Initializes the IWRadialIndicator with an initial total item count
 *  and the number of completed items.
 *
 *  @param totalItemCount    The total number of items that represent a full circle.
 *  @param completeItemCount The number of items completed out of the total item count.
 *
 *  @return The IWRadialIndicator object that handles building the circle
 *          indicator and it's data
 */
- (instancetype)initWithTotalItemCount:(NSInteger)totalItemCount completeItemCount:(NSInteger)completeItemCount;

/*!
 *  Initializes the IWRadialIndicator with an initial total item count
 *  and the number of completed items and a string representing the image name of the circle to be drawn.
 *
 *  @param totalItemCount    The total number of items that represent a full circle.
 *  @param completeItemCount The number of items completed out of the total item count.
 *  @param color             String representing the name of the color of the circle to be drawn.
 *
 *  @return The IWRadialIndicator object that handles building the circle
 *         indicator and it's data
 */
- (instancetype)initWithTotalItemCountAndColor:(NSInteger)totalItemCount completeItemCount:(NSInteger)completeItemCount color:(NSString *)color;

/// The total number of items.
@property (readonly) NSInteger totalItemCount;

/// The number of completed items.
@property (readonly) NSInteger completeItemCount;

/// The number of incomplete items.
@property (readonly) NSInteger incompleteItemCount;

/// The range of images to display in the Radial Indicator widget.
@property (readonly) NSRange imageRange;

/// The length that the Radial Indicator widget image will animate.
@property (readonly) NSTimeInterval animationDuration;

/*!
 * The background image to be displayed in the Radial Indicator widget. The \c groupBackgroundImage draws the text that
 * contains the number of remaining items to complete.
 */
@property (readonly) UIImage *groupBackgroundImage;

@end
