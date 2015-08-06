//
//  ListStyle.h
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

/*!
 * @class ListStyle
 *
 * @discussion This style supports a vertically scrolling item list of items
 *             that can be selected with voice or physically tapped.
 */
@interface ListStyle : JSONModel  <NSCoding>

/*!
 * @discussion Name of icon that a represents recording icon
 */
@property (nonatomic, retain) NSString *icon;

/*!
 *  @discussion Content Title for a ListStyle notification
 */
@property (nonatomic, retain) NSString *title;

/*!
 * @discussion A label that will be shown close to recording icon
 */
@property (nonatomic, retain) NSString *label;

/*!
 * @discussion Controller to be called with the selected item
 */
@property (nonatomic, retain) NSString *intentName;

/*!
 * @discussion Single select list of items made available for speech recognition
 */
@property (nonatomic, retain) NSArray *items;

@end
