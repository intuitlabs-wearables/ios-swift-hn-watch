//
//  NSUserDefaults+NSUserDefaultsExtentions.h
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

/*!
 * @category NSUserDefaultsExtensions
 *
 * @discussion This category adds the ability to save Custom created objects to NSUserDefaults
 */
@interface NSUserDefaults (NSUserDefaultsExtensions)

/*!
 *  @discussion This method can be used to save a custom object to NSUserDefaults.
 *
 *  @param object The custom object to be saved.  Note: it must implement the NSCoding Protocol.
 *  @param key    The NSUserDefaults key to be used to store and retrieve the object.
 */
- (void)saveCustomObject:(id<NSCoding>)object
                     key:(NSString *)key;

/*!
 * @discussion This method can be used to retrieve a custom object from NSUserDefaults.
 *
 * @param key The NSUserDefaults key to be used to store and retrieve the object.
 * @return Returns the Custom Object for the given key.
 */
- (id<NSCoding>)loadCustomObjectWithKey:(NSString *)key;

@end
