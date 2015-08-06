//
//  RadialStyle.h
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
#import <IntuitWearKit/JSONModel.h>

/*!
 * @class RadialStyle
 *
 * @discussion Notification Style that represents a radial graph much like the Apple 
 *             Watch Activity App.
 */
@interface RadialStyle : JSONModel  <NSCoding> 

/*!
 * @discussion Integer representing the color of the circle to draw. 
 *             Current values are 0 = Red, 1 = Green
 */

@property (nonatomic) NSInteger radialColor;

/*!
 * @discussion Header text that will be drawn in the Group above the Circle.
 */
@property (nonatomic, retain) NSString<Optional>* radialHeaderLabelText;

/*!
 * @discussion First line of text that is drawn in the center of the Circle.
 */
@property (nonatomic, retain) NSString<Optional>* radialInnerLabelText;

/*!
 * @discussion Second line of sub text that is drawn in the center of the Circle.
 */
@property (nonatomic, retain) NSString<Optional>* radialInnerSubLabelText;

/*!
 * @discussion Total number of segments in the circle (i.e. Total number of images).
 */
@property (nonatomic) NSInteger radialTotalItemCount;

/*!
 * @discussion Number of completed items which will determine the number of images
 *             drawn.
 */
@property (nonatomic) NSInteger radialCompletedItemsCount;

@end
