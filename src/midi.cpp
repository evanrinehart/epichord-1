/*
   Epichord - a midi sequencer
   Copyright (C) 2008  Evan Rinehart

   This program is free software; you can redistribute it and/or
   modify it under the terms of the GNU General Public License
   as published by the Free Software Foundation; either version 2
   of the License, or (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to

   The Free Software Foundation, Inc.
   51 Franklin Street, Fifth Floor
   Boston, MA  02110-1301, USA
*/


#include <stdlib.h>
#include "seq.h"



char controller_names[128][64] = {
"Bank Select",
"Modulation Wheel",
"Breath Contoller",
"Undefined",
"Foot Controller",
"Portamento Time",
"Data Entry MSB",
"Main Volume",
"Balance",
"Undefined",
"Pan",
"Expresion Controller",
"Effect Control 1",
"Effect Control 2",
"Undefined",
"Undefined",
"General Purpose Controller 1",
"General Purpose Controller 2",
"General Purpose Controller 3",
"General Purpose Controller 4",
"Undefined",
"Undefined",
"Undefined",
"Undefined",
"Undefined",
"Undefined",
"Undefined",
"Undefined",
"Undefined",
"Undefined",
"Undefined",
"Undefined",
"Bank Select LSB",
"Modulation Wheel LSB",
"Breath Contoller LSB",
"Undefined Controller 3 LSB",
"Foot Controller LSB",
"Portamento Time LSB",
"Data Entry LSB",
"Main Volume LSB",
"Balance LSB",
"Undefined Controller 9 LSB",
"Pan LSB",
"Expresion Controller LSB",
"Effect Control 1 LSB",
"Effect Control 2 LSB",
"Undefined Controller 14 LSB",
"Undefined Controller 15 LSB",
"General Purpose Controller 1 LSB",
"General Purpose Controller 2 LSB",
"General Purpose Controller 3 LSB",
"General Purpose Controller 4 LSB",
"Undefined Controller 20 LSB",
"Undefined Controller 21 LSB",
"Undefined Controller 22 LSB",
"Undefined Controller 23 LSB",
"Undefined Controller 24 LSB",
"Undefined Controller 25 LSB",
"Undefined Controller 26 LSB",
"Undefined Controller 27 LSB",
"Undefined Controller 28 LSB",
"Undefined Controller 29 LSB",
"Undefined Controller 30 LSB",
"Undefined Controller 31 LSB",
"Damper Pedal (Sustain)",
"Portamento",
"Sostenuto",
"Soft Pedal",
"Legato Footswitch",
"Hold 2",
"Sound Controller 1 (default: Sound Variation)",
"Sound Controller 2 (default: Timbre/Harmonic Content)",
"Sound Controller 3 (default: Release Time)",
"Sound Controller 4 (default: Attack Time)",
"Sound Controller 5 (default: Brightness)",
"Sound Controller 6",
"Sound Controller 7",
"Sound Controller 8",
"Sound Controller 9",
"Sound Controller 10",
"General Purpose Controller 5",
"General Purpose Controller 6",
"General Purpose Controller 7",
"General Purpose Controller 8",
"Portamento Control",
"Undefined",
"Undefined",
"Undefined",
"Undefined",
"Undefined",
"Undefined",
"Effects 1 Depth",
"Effects 2 Depth (previously Tremolo Depth)",
"Effects 3 Depth (previously Chorus Depth)",
"Effects 4 Depth (previously Detune Depth)",
"Effects 5 Depth (previously Phaser Depth)",
"Data Increment",
"Data Decrement",
"Non-Registered Parameter Number LSB",
"Non-Registered Parameter Number LSB",
"Registered Parameter Number LSB",
"Registered Parameter Number MSB",
"Undefined",
"Undefined",
"Undefined",
"Undefined",
"Undefined",
"Undefined",
"Undefined",
"Undefined",
"Undefined",
"Undefined",
"Undefined",
"Undefined",
"Undefined",
"Undefined",
"Undefined",
"Undefined",
"Undefined",
"Undefined",
"All Sound Off",
"Reset All Controllers",
"Local Control",
"All Notes Off",
"Omni Off",
"Omni On",
"Mono On",
"Poly On"
};


char gm_names[128][64] = {
"Acoustic Grand Piano",
"Bright Acoustic Piano",
"Electric Grand Piano",
"Honky-tonk Piano",
"Rhodes Piano",
"Chorused Piano",
"Harpsichord",
"Clavinet",
"Celesta",
"Glockenspiel",
"Music Box",
"Vibraphone",
"Marimba",
"Xylophone",
"Tubular Bells",
"Dulcimer",
"Hammond Organ",
"Percussive Organ",
"Rock Organ",
"Church Organ",
"Reed Organ",
"Accordion",
"Harmonica",
"Tango Accordion",
"Acoustic Guitar (nylon)",
"Acoustic Guitar (steel)",
"Electric Guitar (jazz)",
"Electric Guitar (clean)",
"Electric Guitar (muted)",
"Overdriven Guitar",
"Distortion Guitar",
"Guitar Harmonics",
"Acoustic Bass",
"Electric Bass (finger)",
"Electric Bass (pick)",
"Fretless Bass",
"Slap Bass 1",
"Slap Bass 2",
"Synth Bass 1",
"Synth Bass 2",
"Violin",
"Viola",
"Cello",
"Contrabass",
"Tremolo Strings",
"Pizzicato Strings",
"Orchestral Harp",
"Timpani",
"String Ensemble 1",
"String Ensemble 2",
"SynthStrings 1",
"SynthStrings 2",
"Choir Aahs",
"Voice Oohs",
"Synth Voice",
"Orchestra Hit",
"Trumpet",
"Trombone",
"Tuba",
"Muted Trumpet",
"French Horn",
"Brass Section",
"Synth Brass 1",
"Synth Brass 2",
"Soprano Sax",
"Alto Sax",
"Tenor Sax",
"Baritone Sax",
"Oboe",
"English Horn",
"Bassoon",
"Clarinet",
"Piccolo",
"Flute",
"Recorder",
"Pan Flute",
"Bottle Blow",
"Shakuhachi",
"Whistle",
"Ocarina",
"Lead 1 (square)",
"Lead 2 (sawtooth)",
"Lead 3 (calliope lead)",
"Lead 4 (chiff lead)",
"Lead 5 (charang)",
"Lead 6 (voice)",
"Lead 7 (fifths)",
"Lead 8 (bass + lead)",
"Pad 1 (new age)",
"Pad 2 (warm)",
"Pad 3 (polysynth)",
"Pad 4 (choir)",
"Pad 5 (bowed)",
"Pad 6 (metallic)",
"Pad 7 (halo)",
"Pad 8 (sweep)",
"FX 1 (rain)",
"FX 2 (soundtrack)",
"FX 3 (crystal)",
"FX 4 (atmosphere)",
"FX 5 (brightness)",
"FX 6 (goblins)",
"FX 7 (echoes)",
"FX 8 (sci-fi)",
"Sitar",
"Banjo",
"Shamisen",
"Koto",
"Kalimba",
"Bagpipe",
"Fiddle",
"Shanai",
"Tinkle Bell",
"Agogo",
"Steel Drums",
"Woodblock",
"Taiko Drum",
"Melodic Tom",
"Synth Drum",
"Reverse Cymbal",
"Guitar Fret Noise",
"Breath Noise",
"Seashore",
"Bird Tweet",
"Telephone Ring",
"Helicopter",
"Applause",
"Gunshot"
};


#include <stdio.h>
//encodes data in e as a midi event placed in buf
int midi_encode(mevent* e, int chan, unsigned char* buf, size_t* n){

  buf[0] = e->type | chan;
  buf[1] = e->value1;

//printf("%u %u %u\n",e->type,chan,e->type | chan);

  switch(e->type){
    case -1:
      return -1;
    case 0xC0:
    case 0xD0:
      *n = 2;
      break;
  }

  buf[2] = e->value2;

  *n = 3;

  return 0;
}

//decodes midi data and creates a new mevent
int midi_decode(char* buf, mevent* e){
  e->type = buf[0] & 0xf0;
  e->value1 = buf[1];

  switch(e->type){//messages with no third byte
    case 0xC0:
    case 0xD0:
      return 0;
  }

  e->value2 = buf[2];
}
