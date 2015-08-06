//
//  Page.h
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

@protocol Page @end

/*!
 * @class Page
 *
 * @discussion Page declaration for multi-page notifications
 */
@interface Page : JSONModel  <NSCoding>

/*!
 * @discussion Title for this page
 */
@property (nonatomic, retain) NSString *pageTitle;

/*!
 * @discussion Text content for this page, e.g. HTML encoded text
 */
@property (nonatomic, retain) NSString *pageText;

/*!
 * @discussion Name of resource to use for the background of the page. NOTE: This resource must already exist.
 */
@property (nonatomic, retain) NSString<Optional> *pageBackground;

//- (instancetype)init;
@end
