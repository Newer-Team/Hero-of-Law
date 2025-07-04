#ifndef Z64VOICE_H
#define Z64VOICE_H

#include "ultra64/types.h"
#include "ultra64/message.h"
#include "PR/os_voice.h"

#include "unk.h"

typedef struct {
    /* 0x000 */ u16 words[20][15]; // 20 words, each with up to 15 syllables
    /* 0x258 */ u8 numWords;
} OSVoiceDictionary; // size = 0x25C

void AudioVoice_Noop(void);
void AudioVoice_ResetWord(void);
void AudioVoice_InitWord(u16 wordId);
u16 AudioVoice_GetWord(void);
void AudioVoice_Update(void);
s32 func_801A51F0(s32 errorCode);
s32 func_801A5228(OSVoiceDictionary* dict);
OSVoiceData* func_801A5390(void);
void func_801A53E8(u16 distance, u16 answerNum, u16 warning, u16 voiceLevel, u16 voiceRelLevel);
u8* AudioVoice_GetVoiceMaskPattern(void);
s32 AudioVoice_InitWordImplAlt(u16 wordId);
s32 AudioVoice_InitWordImpl(u16 wordId);
s32 func_801A5808(void);
void AudioVoice_ResetData(void);

extern OSVoiceHandle gVoiceHandle;

#endif
