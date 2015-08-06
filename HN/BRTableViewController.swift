//
//  BRTableViewController.swift
//  HN
//
//  Created by Liu, Frank on 6/29/15.
//  Copyright (c) 2015 fliu. All rights reserved.
//

import UIKit

class BRTableViewController: UITableViewController, NSXMLParserDelegate{
    
    var parser:NSXMLParser = NSXMLParser()
    var blogPosts: [BlogPost] = []
    
    var postTitle = String()
    var postLink = String()
    var eName = String()

    override func viewDidLoad() {
        super.viewDidLoad()
        
        let url = NSURL(string: "https://news.ycombinator.com/rss")!
        parser = NSXMLParser(contentsOfURL: url)!
        parser.delegate = self
        parser.parse()

        // Uncomment the following line to preserve selection between presentations
        // self.clearsSelectionOnViewWillAppear = false

        // Uncomment the following line to display an Edit button in the navigation bar for this view controller.
        // self.navigationItem.rightBarButtonItem = self.editButtonItem()
    }
    
    func parser(parser: NSXMLParser, didStartElement elementName: String, namespaceURI: String?, qualifiedName qName: String?, attributes attributeDict: [NSObject : AnyObject]) {
        eName = elementName
        if elementName == "item" {
            postTitle = String()
            postLink = String()
        }
    }
    
    func parser(parser: NSXMLParser, foundCharacters string: String?) {
        let data = string?.stringByTrimmingCharactersInSet(NSCharacterSet.whitespaceAndNewlineCharacterSet())
        if (!data!.isEmpty){
            if eName == "title" {
                postTitle += data!
            } else if eName == "link" {
                postLink += data!
            }
        }
    }
    
    func parser(parser: NSXMLParser, didEndElement elementName: String, namespaceURI: String?, qualifiedName qName: String?) {
        if elementName == "item" {
            let blogPost = BlogPost()
            blogPost.postTitle = postTitle
            blogPost.postLink = postLink
            blogPosts.append(blogPost)
        }
    }

    override func didReceiveMemoryWarning() {
        super.didReceiveMemoryWarning()
        // Dispose of any resources that can be recreated.
    }

    // MARK: - Table view data source

    override func numberOfSectionsInTableView(tableView: UITableView) -> Int {
        // #warning Potentially incomplete method implementation.
        // Return the number of sections.
        return 1
    }

    override func tableView(tableView: UITableView, numberOfRowsInSection section: Int) -> Int {
        // #warning Incomplete method implementation.
        // Return the number of rows in the section.
        return blogPosts.count
    }

    
    override func tableView(tableView: UITableView, cellForRowAtIndexPath indexPath: NSIndexPath) -> UITableViewCell {
        let cell = tableView.dequeueReusableCellWithIdentifier("Cell", forIndexPath: indexPath) as! UITableViewCell

        // Configure the cell...
        
        let blogPost = blogPosts[indexPath.row]
        cell.textLabel!.text = blogPost.postTitle

        return cell
    }
    

    /*
    // Override to support conditional editing of the table view.
    override func tableView(tableView: UITableView, canEditRowAtIndexPath indexPath: NSIndexPath) -> Bool {
        // Return NO if you do not want the specified item to be editable.
        return true
    }
    */

    /*
    // Override to support editing the table view.
    override func tableView(tableView: UITableView, commitEditingStyle editingStyle: UITableViewCellEditingStyle, forRowAtIndexPath indexPath: NSIndexPath) {
        if editingStyle == .Delete {
            // Delete the row from the data source
            tableView.deleteRowsAtIndexPaths([indexPath], withRowAnimation: .Fade)
        } else if editingStyle == .Insert {
            // Create a new instance of the appropriate class, insert it into the array, and add a new row to the table view
        }    
    }
    */

    /*
    // Override to support rearranging the table view.
    override func tableView(tableView: UITableView, moveRowAtIndexPath fromIndexPath: NSIndexPath, toIndexPath: NSIndexPath) {

    }
    */

    /*
    // Override to support conditional rearranging of the table view.
    override func tableView(tableView: UITableView, canMoveRowAtIndexPath indexPath: NSIndexPath) -> Bool {
        // Return NO if you do not want the item to be re-orderable.
        return true
    }
    */

    
    // MARK: - Navigation

    // In a storyboard-based application, you will often want to do a little preparation before navigation
    override func prepareForSegue(segue: UIStoryboardSegue, sender: AnyObject?) {
        // Get the new view controller using [segue destinationViewController].
        // Pass the selected object to the new view controller.
        if segue.identifier == "viewpost" {
            let blogPost: BlogPost = blogPosts[tableView.indexPathForSelectedRow()!.row]
            let viewController = segue.destinationViewController as! PostViewController
            viewController.postLink = blogPost.postLink
        }
    }

}
