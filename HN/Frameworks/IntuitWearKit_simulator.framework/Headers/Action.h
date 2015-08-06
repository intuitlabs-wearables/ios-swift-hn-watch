//
//  Action.h
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

@protocol Action @end

/*!
 * @class Action
 *
 * @discussion Actions that can be triggered by a Notification
 */
@interface Action : JSONModel  <NSCoding>

/*!
 * @discussion The name of the action icon.  On iOS this must be a name of an existing icon.
 */
@property (nonatomic, retain) NSString *icon;

/*!
 * @discussion The name displayed on the action button.
 */
@property (nonatomic, retain) NSString *actionName;

/**
 *  @discussion The name of the controller to launch when the action is selected.
 */
@property (nonatomic, retain) NSString *intentName;

/*!
 *  Extra parameters for the intent launched.
 */
@property (nonatomic, retain) NSArray<Optional> *extras;

@end
