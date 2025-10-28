//////////////////////////////////////////////////////////////////////////
/// Copyright (c) 1988-2025 $organization$
///
/// This software is provided by the author and contributors ``as is''
/// and any express or implied warranties, including, but not limited to,
/// the implied warranties of merchantability and fitness for a particular
/// purpose are disclaimed. In no event shall the author or contributors
/// be liable for any direct, indirect, incidental, special, exemplary,
/// or consequential damages (including, but not limited to, procurement
/// of substitute goods or services; loss of use, data, or profits; or
/// business interruption) however caused and on any theory of liability,
/// whether in contract, strict liability, or tort (including negligence
/// or otherwise) arising in any way out of the use of this software,
/// even if advised of the possibility of such damage.
///
///   File: ViewController.mm
///
/// Author: $author$
///   Date: 10/20/2025
//////////////////////////////////////////////////////////////////////////
#import "ViewController.h"
#include "uLucidity/Application/uDentify/UI/UIKit/uDentifyThread.hh"

@interface ViewController ()

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    self.view.backgroundColor = [UIColor blackColor];

    self.User.text = @"user";
    self.Resource.text = @"resource";
    self.Password.text = @"password";
    self.Value.text = nil;

    self.Ok.titleLabel.text = @"Ok";
    self.Ok.titleLabel.font = [UIFont boldSystemFontOfSize:18.0];
    self.Ok.backgroundColor = [UIColor lightGrayColor];
    self.Ok.layer.borderColor = [UIColor grayColor].CGColor;
    self.Ok.layer.borderWidth = 3.0;
    self.Ok.layer.cornerRadius = 9.0;
    self.Ok.clipsToBounds = YES;

    self.Clear.titleLabel.text = @"Clear";
    self.Clear.titleLabel.font = [UIFont boldSystemFontOfSize:18.0];
    self.Clear.backgroundColor = [UIColor lightGrayColor];
    self.Clear.layer.borderColor = [UIColor grayColor].CGColor;
    self.Clear.layer.borderWidth = 3.0;
    self.Clear.layer.cornerRadius = 9.0;
    self.Clear.clipsToBounds = YES;

    self.Done.titleLabel.text = @"Done";
    self.Done.titleLabel.font = [UIFont boldSystemFontOfSize:18.0];
    self.Done.backgroundColor = [UIColor lightGrayColor];
    self.Done.layer.borderColor = [UIColor grayColor].CGColor;
    self.Done.layer.borderWidth = 3.0;
    self.Done.layer.cornerRadius = 9.0;
    self.Done.clipsToBounds = YES;

    self.valueUnset = YES;
    self.threadDone = YES;
    NSLog(@"((_thread = [[uDentifyThread alloc] init]))...");
    if ((_thread = [[uDentifyThread alloc] init])) {
        NSLog(@"...((_thread = [[uDentifyThread alloc] init]))");
    } else {
        NSLog(@"...failed on ((_thread = [[uDentifyThread alloc] init]))");
    }
}


- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}


- (IBAction)User:(id)sender {
    NSLog(@"...User: %@", self.User.text);
}

- (IBAction)Resource:(id)sender {
    NSLog(@"...Resource: %@", self.Resource.text);
}

- (IBAction)Password:(id)sender {
    NSLog(@"...Password: %@", self.Password.text);
}

- (IBAction)Value:(id)sender {
    NSLog(@"...Value: %@", self.Value.text);
}

- (IBAction)Ok:(id)sender {
    NSLog(@"...Ok");
    NSLog(@"User: %@", self.User.text);
    NSLog(@"Resource: %@", self.Resource.text);
    NSLog(@"Password: %@", self.Password.text);

    NSLog(@"((_thread))...");
    if ((_thread)) {

        NSLog(@"((self.threadDone))...");
        if ((self.threadDone)) {
            const char *userChars = [self.User.text UTF8String], 
                       *resourceChars = [self.Resource.text UTF8String], 
                       *passwordChars = [self.Password.text UTF8String];

            self.threadDone = NO;
            NSLog(@"self.Value.text = nil...");
            self.Value.text = nil;

            NSLog(@"[_thread start:self]...");
            [_thread start:self User:self.User.text Resource:self.Resource.text Password:self.Password.text];
            NSLog(@"...[_thread start:self]");
        } else {
            NSLog(@"...failed on ((self.threadDone))");
        }
    } else {
        NSLog(@"...failed on ((_thread))");;
    }
}

- (IBAction)Clear:(id)sender {
    NSLog(@"...Clear");
    NSLog(@"self.Value.text = nil...");
    self.Value.text = nil;
}

- (IBAction)Done:(id)sender {
    NSLog(@"...Done");
    NSLog(@"exit(0)...");
    exit(0);
}

///////////////////////////////////////////////////////////////////////
/// onThreadWillStart
- (void)onThreadWillStart:(NSThread*)thread {
    NSLog(@"...onThreadWillStart");
    NSLog(@"((_thread))...");
    if ((_thread)) {
        NSLog(@"...((_thread))");
    } else {
        NSLog(@"...failed on ((_thread))");
    }
}

///////////////////////////////////////////////////////////////////////
/// onThreadFnished
- (void)onThreadFnished:(NSThread*)thread {
    NSLog(@"...onThreadFnished");
    NSLog(@"((_thread))...");
    if ((_thread)) {
        NSLog(@"((self.valueUnset))...");
        if ((self.valueUnset)) {
            NSLog(@"...((self.valueUnset))");
            NSLog(@"self.Value.text = self.Password.text...");
            self.Value.text = self.Password.text;
            NSLog(@"...self.Value.text = self.Password.text");
        } else {
            NSLog(@"...failed on ((self.valueUnset))");
        }
        self.valueUnset = YES;
        self.threadDone = YES;
    } else {
        NSLog(@"...failed on ((_thread))");
    }
}

///////////////////////////////////////////////////////////////////////
/// onThreadResult
- (void)onThreadResult:(NSString*)result {
    NSLog(@"...onThreadResult");
    NSLog(@"((result))...");
    if ((result)) {
        NSLog(@"self.Value.text = %@%@", result, @"...");
        self.Value.text = result;
        NSLog(@"...self.Value.text = %@", result);
        self.valueUnset = NO;
    } else {
        NSLog(@"...failed on ((result))");
    }
}

@end
