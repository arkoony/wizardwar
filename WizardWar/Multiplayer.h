//
//  PlayerService.h
//  WizardWar
//
//  Created by Sean Hess on 5/29/13.
//  Copyright (c) 2013 The LAB. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "Spell.h"
#import "Wizard.h"

@protocol MultiplayerDelegate <NSObject>
-(void)mpDidAddSpell:(Spell*)spell;
-(void)mpDidUpdate:(NSDictionary*)updates spellWithId:(NSString*)spellId;
-(void)mpDidRemoveSpellWithId:(NSString*)spellId;

-(void)mpDidAddPlayer:(Wizard*)player;
-(void)mpDidUpdate:(NSDictionary*)updates playerWithName:(NSString*)name;
-(void)mpDidRemovePlayerWithName:(NSString*)name;
@end


@protocol Multiplayer <NSObject>
@property (weak, nonatomic) id<MultiplayerDelegate>delegate;
-(void)connectToMatchId:(NSString*)matchId;
-(void)disconnect;

-(void)addPlayer:(Wizard*)player;
-(void)updatePlayer:(Wizard*)player;
-(void)removePlayer:(Wizard*)player;

-(void)addSpell:(Spell*)spell;
-(void)updateSpell:(Spell*)spell;
-(void)removeSpells:(NSArray*)spell;
@end
