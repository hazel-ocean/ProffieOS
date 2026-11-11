#ifdef CONFIG_TOP
#include "proffieboard_config.h"
#define NUM_BLADES 2
#define NUM_BUTTONS 2
#define VOLUME 1200
const unsigned int maxLedsPerStrip = 144;
#define CLASH_THRESHOLD_G 2.0
#define ENABLE_AUDIO
#define ENABLE_MOTION
#define ENABLE_WS2811
#define ENABLE_SD
#define DISABLE_DIAGNOSTIC_COMMANDS
#define SHARED_POWER_PINS

//#define ORIENTATION ORIENTATION_USB_TOWARDS_BLADE     
#define FETT263_TWIST_ON_NO_BM                          
#define FETT263_STAB_ON_NO_BM                                               

#define MOTION_TIMEOUT 60 * 3 * 1000                  

#define FETT263_STAB_ON                                
#define FETT263_TWIST_ON                                
#define FETT263_TWIST_OFF                               
#define FETT263_TRACK_PLAYER_NO_PROMPTS
#endif

#ifdef CONFIG_PROP
#include "../props/saber_fett263_buttons.h"
#endif

#ifdef CONFIG_PRESETS
Preset presets[] = {
  // Luke ROTJ
  { "Luke ROTJ;common", "tracks/Luke ROTJ.wav",
    StylePtr<Layers<RandomFlicker<RotateColorsX<Variation,Green>,RotateColorsX<Variation,Rgb16<0,39252,0>>>,LockupTrL<Layers<AlphaL<AudioFlickerL<White>,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Int<4000>,Int<26000>>,Int<6000>>,Scale<SwingSpeed<100>,Int<14000>,Int<18000>>>>,AlphaL<White,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Int<4000>,Int<26000>>,Int<6000>>,Int<10000>>>>,TrConcat<TrInstant,White,TrFade<400>>,TrConcat<TrInstant,White,TrFade<400>>,SaberBase::LOCKUP_NORMAL>,ResponsiveLightningBlockL<Strobe<White,AudioFlicker<White,Blue>,50,1>,TrConcat<TrInstant,AlphaL<White,Bump<Int<12000>,Int<18000>>>,TrFade<200>>,TrConcat<TrInstant,HumpFlickerL<AlphaL<White,Int<16000>>,30>,TrSmoothFade<600>>>,ResponsiveStabL<Red>,ResponsiveBlastL<White,Int<400>,Scale<SwingSpeed<200>,Int<100>,Int<400>>>,ResponsiveClashL<White,TrInstant,TrFade<400>,Scale<BladeAngle<0,16000>,Int<4000>,Int<26000>>,Int<6000>,Int<20000>>,LockupTrL<AlphaL<BrownNoiseFlickerL<White,Int<300>>,SmoothStep<Int<30000>,Int<5000>>>,TrWipeIn<400>,TrFade<300>,SaberBase::LOCKUP_DRAG>,LockupTrL<AlphaL<Mix<TwistAngle<>,Red,Orange>,SmoothStep<Int<28000>,Int<5000>>>,TrWipeIn<600>,TrFade<300>,SaberBase::LOCKUP_MELT>,InOutTrL<TrWipeSparkTip<White,300>,TrWipeInSparkTip<White,500>>>>(),
    StylePtr<Blinking<White,Black,500,500>>(),
    "0"},
  // Vader ROTJ
  { "Vader ROTJ;common", "tracks/Vader ROTJ.wav",
      StylePtr<Layers<HumpFlicker<RotateColorsX<Variation,Rgb<200,0,0>>,RotateColorsX<Variation,Rgb<100,0,0>>,50>,
      LockupTrL<Layers<AlphaL<AudioFlickerL<Rgb<255,240,80>>,Bump<Sin<Int<10>,Int<10000>,Int<20000>>>>,AlphaL<LemonChiffon,Bump<Sin<Int<10>,Int<10000>,Int<20000>>>>>,TrConcat<TrInstant,TransitionEffect<Rgb<255,180,50>,LemonChiffon,TrInstant,TrFade<200>,EFFECT_LOCKUP_BEGIN>,TrFade<400>>,TrConcat<TrInstant,AlphaL<White,Int<0>>,TrWaveX<TransitionEffect<LemonChiffon,Rgb<255,180,50>,TrInstant,TrFade<200>,EFFECT_LOCKUP_BEGIN>,Int<300>,Int<100>,Int<400>,Sin<Int<10>,Int<10000>,Int<20000>>>>,SaberBase::LOCKUP_NORMAL>,
      LockupTrL<AlphaL<White,LayerFunctions<Bump<Scale<SlowNoise<Int<2000>>,Int<3000>,Int<16000>>,Scale<BrownNoiseF<Int<10>>,Int<14000>,Int<8000>>>,Bump<Scale<SlowNoise<Int<2300>>,Int<26000>,Int<8000>>,Scale<NoisySoundLevel,Int<5000>,Int<10000>>>,Bump<Scale<SlowNoise<Int<2300>>,Int<20000>,Int<30000>>,Scale<IsLessThan<SlowNoise<Int<1500>>,Int<8000>>,Scale<NoisySoundLevel,Int<5000>,Int<0>>,Int<0>>>>>,TrConcat<TrInstant,AlphaL<White,Bump<Int<12000>,Int<18000>>>,TrFade<200>>,TrConcat<TrInstant,HumpFlickerL<AlphaL<White,Int<16000>>,30>,TrSmoothFade<600>>,SaberBase::LOCKUP_LIGHTNING_BLOCK>,
      ResponsiveStabL<Orange,TrWipeIn<600>,TrWipe<600>>,
      EffectSequence<EFFECT_BLAST,ResponsiveBlastL<TransitionEffect<Rgb<255,240,80>,LemonChiffon,TrInstant,TrFade<50>,EFFECT_BLAST>,Int<400>,Scale<SwingSpeed<200>,Int<100>,Int<400>>>,Layers<ResponsiveBlastFadeL<TransitionEffect<Rgb<255,240,80>,LemonChiffon,TrInstant,TrFade<100>,EFFECT_BLAST>,Scale<SwingSpeed<200>,Int<10000>,Int<18000>>>,ResponsiveBlastFadeL<LemonChiffon,Scale<SwingSpeed<200>,Int<4000>,Int<10000>>>>,BlastL<TransitionEffect<Rgb<255,240,80>,LemonChiffon,TrInstant,TrFade<50>,EFFECT_BLAST>>,ResponsiveBlastL<TransitionEffect<Rgb<255,240,80>,LemonChiffon,TrInstant,TrFade<50>,EFFECT_BLAST>>>,BlastL<TransitionEffect<Rgb<255,240,80>,LemonChiffon,TrInstant,TrFade<50>,EFFECT_BLAST>>,
      TransitionEffectL<TrConcat<TrInstant,Moccasin,TrDelay<25>,AlphaL<TransitionEffect<TransitionEffect<Strobe<NavajoWhite,Moccasin,20,20>,BrownNoiseFlicker<NavajoWhite,Moccasin,300>,TrInstant,TrFade<300>,EFFECT_CLASH>,NavajoWhite,TrInstant,TrDelay<150>,EFFECT_CLASH>,Bump<Scale<BladeAngle<>,Int<25000>,Int<8000>>,Int<18000>>>,TrFade<600>>,EFFECT_CLASH>,
      TransitionEffectL<TrConcat<TrInstant,AudioFlickerL<RotateColorsX<Variation,OrangeRed>>,TrFade<1200>>,EFFECT_IGNITION>,
      LockupTrL<AlphaL<BrownNoiseFlickerL<White,Int<300>>,SmoothStep<Int<30000>,Int<5000>>>,TrWipeIn<400>,TrFade<300>,SaberBase::LOCKUP_DRAG>,
      LockupTrL<AlphaL<Mix<TwistAngle<>,Rgb<255,200,0>,DarkOrange>,SmoothStep<Int<28000>,Int<5000>>>,TrWipeIn<600>,TrFade<300>,SaberBase::LOCKUP_MELT>,
      InOutTrL<TrWipe<450>,TrWipeIn<1000>,Black>>>(),
    StylePtr<Blinking<White,Black,500,500>>(),
    "0"},
  // Luke ESB
  { "Luke ESB;common", "tracks/Luke ESB.wav",
  StylePtr<Layers<
  HumpFlicker<Rgb<55,155,255>,Rgb<28,78,128>,7>,
  LockupTrL<Layers<
    AlphaL<Blinking<Moccasin,Strobe<NavajoWhite,Rgb<255,147,50>,15,30>,60,500>,Bump<Scale<BladeAngle<5000,28000>,Scale<BladeAngle<8000,16000>,Int<3000>,Int<44000>>,Int<3000>>,Scale<SlowNoise<Int<3000>>,Int<8000>,Int<18000>>>>,
    AlphaL<Blinking<BrownNoiseFlicker<Moccasin,Rgb<255,197,100>,50>,BrownNoiseFlicker<Moccasin,Rgb<255,197,100>,50>,100,500>,Bump<Scale<BladeAngle<5000,28000>,Scale<BladeAngle<8000,16000>,Int<3000>,Int<44000>>,Int<3000>>,Int<15000>>>>,TrConcat<TrInstant,AlphaL<Blinking<White,Strobe<BrownNoiseFlicker<Moccasin,Rgb<255,197,100>,500>,Black,15,30>,60,500>,Bump<Scale<BladeAngle<5000,28000>,Scale<BladeAngle<8000,16000>,Int<3000>,Int<44000>>,Int<3000>>,Scale<SlowNoise<Int<3000>>,Int<25000>,Int<32000>>>>,TrFade<500>>,TrSmoothFade<300>,SaberBase::LOCKUP_NORMAL>,
  TransitionEffectL<TrConcat<TrInstant,AlphaL<Strobe<Moccasin,Rgb<255,197,100>,20,30>,Bump<Scale<BladeAngle<5000,28000>,Scale<BladeAngle<8000,16000>,Int<3000>,Int<44000>>,Int<3000>>,Int<15000>>>,TrFade<300>>,EFFECT_LOCKUP_BEGIN>,
  TransitionEffectL<TrConcat<TrInstant,HumpFlickerL<Strobe<AlphaL<PeachPuff,Int<20000>>,Black,20,30>,30>,TrSmoothFade<250>>,EFFECT_LOCKUP_BEGIN>,
  TransitionEffectL<TrConcat<TrInstant,PeachPuff,TrDelay<25>>,EFFECT_LOCKUP_BEGIN>,
  TransitionEffectL<TrConcat<TrInstant,Strobe<Rgb<100,100,150>,Black,20,30>,TrFade<200>,BrownNoiseFlickerL<AlphaL<PeachPuff,Int<16000>>,Int<50>>,TrJoinR<TrWipe<200>,TrWipeIn<200>,TrFade<300>>>,EFFECT_LOCKUP_END>,
  ResponsiveLightningBlockL<Strobe<White,AudioFlicker<White,White>,50,1>,TrConcat<TrInstant,AlphaL<Azure,Bump<Int<12000>,Int<18000>>>,TrFade<500>>,TrConcat<TrInstant,HumpFlickerL<AlphaL<LemonChiffon,Int<16000>>,30>,TrSmoothFade<600>>>,
  AlphaL<Black,SmoothStep<Scale<SlowNoise<Int<1600>>,Int<1000>,Int<4000>>,Int<-4000>>>,
  ResponsiveStabL<OrangeRed>,
  ResponsiveBlastWaveL<Sparkle<OrangeRed,White,9999,399>,Int<500>,Scale<SwingSpeed<200>,Int<200>,Int<200>>,Int<999>,Int<25000>>,
  TransitionEffectL<TrConcat<TrInstant,Moccasin,TrDelay<25>,AlphaL<TransitionEffect<TransitionEffect<Strobe<LemonChiffon,Cornsilk,20,20>,BrownNoiseFlicker<LemonChiffon,Cornsilk,300>,TrInstant,TrFade<300>,EFFECT_CLASH>,NavajoWhite,TrInstant,TrDelay<150>,EFFECT_CLASH>,Bump<Scale<BladeAngle<>,Int<25000>,Int<8000>>,Int<18000>>>,TrFade<600>>,EFFECT_CLASH>,
  LockupTrL<AlphaL<BrownNoiseFlickerL<White,Int<300>>,SmoothStep<Int<30000>,Int<5000>>>,TrWipeIn<400>,TrFade<300>,SaberBase::LOCKUP_DRAG>,
  LockupTrL<AlphaL<Mix<TwistAngle<>,Red,Orange>,SmoothStep<Int<28000>,Int<5000>>>,TrWipeIn<600>,TrFade<300>,SaberBase::LOCKUP_MELT>,
  InOutTrL<TrWipe<250>,TrWipeIn<1100>>>>(),
    StylePtr<Blinking<White,Black,500,500>>(),
    "0"},
  // Vader ESB
  { "Vader ESB;common", "tracks/Vader ESB.wav",
      StylePtr<Layers<
      Layers<
        RotateColorsX<Variation,Red>,
        RandomL<RotateColorsX<Variation,Rgb<128,0,0>>>,
        RandomL<RotateColorsX<Variation,Rgb<64,0,0>>>>,
      LockupTrL<Layers<
        AlphaL<Blinking<White,Strobe<White,LemonChiffon,15,30>,60,500>,Bump<Scale<BladeAngle<5000,28000>,Scale<BladeAngle<8000,16000>,Int<3000>,Int<44000>>,Int<3000>>,Scale<SlowNoise<Int<3000>>,Int<8000>,Int<18000>>>>,
        AlphaL<Blinking<BrownNoiseFlicker<LemonChiffon,White,50>,BrownNoiseFlicker<LemonChiffon,White,50>,100,500>,Bump<Scale<BladeAngle<5000,28000>,Scale<BladeAngle<8000,16000>,Int<3000>,Int<44000>>,Int<3000>>,Int<14999>>>>,TrConcat<TrInstant,AlphaL<Blinking<LightYellow,Strobe<BrownNoiseFlicker<LemonChiffon,White,500>,LemonChiffon,15,30>,60,500>,Bump<Scale<BladeAngle<5000,28000>,Scale<BladeAngle<8000,16000>,Int<3000>,Int<44000>>,Int<3000>>,Scale<SlowNoise<Int<3000>>,Int<25000>,Int<32000>>>>,TrFade<300>>,TrSmoothFade<250>,SaberBase::LOCKUP_NORMAL>,
      TransitionEffectL<TrConcat<TrInstant,AlphaL<Strobe<LemonChiffon,White,20,30>,Bump<Scale<BladeAngle<5000,28000>,Scale<BladeAngle<8000,16000>,Int<3000>,Int<44000>>,Int<3000>>,Int<15000>>>,TrFade<300>>,EFFECT_LOCKUP_BEGIN>,
      TransitionEffectL<TrConcat<TrInstant,HumpFlickerL<Strobe<AlphaL<LightYellow,Int<20000>>,White,20,30>,30>,TrSmoothFade<250>>,EFFECT_LOCKUP_BEGIN>,
      TransitionEffectL<TrConcat<TrInstant,LightYellow,TrDelay<25>>,EFFECT_LOCKUP_BEGIN>,
      TransitionEffectL<TrConcat<TrInstant,Strobe<White,LemonChiffon,20,30>,TrFade<200>,BrownNoiseFlickerL<AlphaL<LightYellow,Int<16000>>,Int<50>>,TrJoinR<TrWipe<200>,TrWipeIn<200>,TrFade<300>>>,EFFECT_LOCKUP_END>,
      LockupTrL<AlphaL<White,LayerFunctions<Bump<Scale<SlowNoise<Int<2000>>,Int<3000>,Int<16000>>,Scale<BrownNoiseF<Int<10>>,Int<14000>,Int<8000>>>,Bump<Scale<SlowNoise<Int<2300>>,Int<26000>,Int<8000>>,Scale<NoisySoundLevel,Int<5000>,Int<10000>>>,Bump<Scale<SlowNoise<Int<2300>>,Int<20000>,Int<30000>>,Scale<IsLessThan<SlowNoise<Int<1500>>,Int<8000>>,Scale<NoisySoundLevel,Int<5000>,Int<0>>,Int<0>>>>>,TrConcat<TrInstant,AlphaL<White,Bump<Int<12000>,Int<18000>>>,TrFade<200>>,TrConcat<TrInstant,HumpFlickerL<AlphaL<White,Int<16000>>,30>,TrSmoothFade<600>>,SaberBase::LOCKUP_LIGHTNING_BLOCK>,
      AlphaL<Black,SmoothStep<Scale<SlowNoise<Int<1600>>,Int<1000>,Int<6000>>,Int<-6000>>>,
      ResponsiveStabL<Orange>,
      EffectSequence<EFFECT_BLAST,ResponsiveBlastL<TransitionEffect<Rgb<255,240,80>,LemonChiffon,TrInstant,TrFade<50>,EFFECT_BLAST>,Int<400>,Scale<SwingSpeed<200>,Int<100>,Int<400>>>,Layers<ResponsiveBlastFadeL<TransitionEffect<Rgb<255,240,80>,LemonChiffon,TrInstant,TrFade<100>,EFFECT_BLAST>,Scale<SwingSpeed<200>,Int<10000>,Int<18000>>>,ResponsiveBlastFadeL<LemonChiffon,Scale<SwingSpeed<200>,Int<4000>,Int<10000>>>>,BlastL<TransitionEffect<Rgb<255,240,80>,LemonChiffon,TrInstant,TrFade<50>,EFFECT_BLAST>>,ResponsiveBlastL<TransitionEffect<Rgb<255,240,80>,LemonChiffon,TrInstant,TrFade<50>,EFFECT_BLAST>>>,BlastL<TransitionEffect<Rgb<255,240,80>,LemonChiffon,TrInstant,TrFade<50>,EFFECT_BLAST>>,
      TransitionEffectL<TrConcat<TrInstant,Moccasin,TrDelay<25>,AlphaL<TransitionEffect<TransitionEffect<Strobe<NavajoWhite,Moccasin,20,20>,BrownNoiseFlicker<NavajoWhite,Moccasin,300>,TrInstant,TrFade<300>,EFFECT_CLASH>,NavajoWhite,TrInstant,TrDelay<150>,EFFECT_CLASH>,Bump<Scale<BladeAngle<>,Int<25000>,Int<8000>>,Int<18000>>>,TrFade<600>>,EFFECT_CLASH>,
      LockupTrL<AlphaL<BrownNoiseFlickerL<White,Int<300>>,SmoothStep<Int<30000>,Int<5000>>>,TrWipeIn<400>,TrFade<300>,SaberBase::LOCKUP_DRAG>,
      LockupTrL<AlphaL<Mix<TwistAngle<>,Rgb<255,200,0>,DarkOrange>,SmoothStep<Int<28000>,Int<5000>>>,TrWipeIn<600>,TrFade<300>,SaberBase::LOCKUP_MELT>,
      InOutTrL<TrWipe<1000>,TrWipeIn<1060>>>>(),
    StylePtr<Blinking<White,Black,500,500>>(),
    "0"},
  // Luke ANH
  { "Luke ANH;common", "tracks/Luke ANH.wav",
  StylePtr<Layers<
  Layers<
    RandomPerLEDFlicker<Rgb<110,225,255>,Rgb<55,113,128>>,
    AudioFlickerL<RotateColorsX<Variation,Rgb<73,150,191>>>>,
  LockupTrL<Layers<AlphaL<Blinking<LemonChiffon,Strobe<Rgb<239,182,43>,Moccasin,15,30>,60,500>,Bump<Scale<BladeAngle<5000,28000>,Scale<BladeAngle<8000,16000>,Int<3000>,Int<44000>>,Int<3000>>,Scale<SlowNoise<Int<3000>>,Int<8000>,Int<18000>>>>,AlphaL<Blinking<BrownNoiseFlicker<LemonChiffon,Moccasin,50>,BrownNoiseFlicker<LemonChiffon,Rgb<239,182,43>,50>,100,500>,Bump<Scale<BladeAngle<5000,28000>,Scale<BladeAngle<8000,16000>,Int<3000>,Int<44000>>,Int<3000>>,Int<14599>>>>,TrConcat<TrInstant,AlphaL<Blinking<White,Strobe<BrownNoiseFlicker<Moccasin,Rgb<239,182,43>,500>,White,15,30>,60,500>,Bump<Scale<BladeAngle<5000,28000>,Scale<BladeAngle<8000,16000>,Int<3000>,Int<44000>>,Int<3000>>,Scale<SlowNoise<Int<3000>>,Int<25000>,Int<32000>>>>,TrFade<300>>,TrSmoothFade<250>,SaberBase::LOCKUP_NORMAL>,
  ResponsiveLightningBlockL<Strobe<White,AudioFlicker<White,White>,50,1>,TrConcat<TrInstant,AlphaL<Azure,Bump<Int<12000>,Int<18000>>>,TrFade<500>>,TrConcat<TrInstant,HumpFlickerL<AlphaL<LemonChiffon,Int<16000>>,30>,TrSmoothFade<600>>>,
  ResponsiveStabL<OrangeRed>,
  ResponsiveBlastWaveL<Sparkle<OrangeRed,White,9999,399>,Int<500>,Scale<SwingSpeed<200>,Int<200>,Int<200>>,Int<999>,Int<25000>>,
  TransitionEffectL<TrConcat<TrInstant,Moccasin,TrDelay<25>,AlphaL<TransitionEffect<TransitionEffect<Sparkle<Rgb<212,175,55>,Rgb<180,130,0>>,Sparkle<Rgb<212,175,55>>,TrInstant,TrFade<300>,EFFECT_CLASH>,NavajoWhite,TrInstant,TrDelay<150>,EFFECT_CLASH>,Bump<Scale<BladeAngle<>,Int<25000>,Int<8000>>,Int<18000>>>,TrFade<600>>,EFFECT_CLASH>,
  LockupTrL<AlphaL<BrownNoiseFlickerL<White,Int<300>>,SmoothStep<Int<30000>,Int<5000>>>,TrWipeIn<400>,TrFade<300>,SaberBase::LOCKUP_DRAG>,
  LockupTrL<AlphaL<Mix<TwistAngle<>,Red,Orange>,SmoothStep<Int<27000>,Int<5000>>>,TrWipeIn<600>,TrFade<600>,SaberBase::LOCKUP_MELT>,
  InOutTrL<TrWipe<250>,TrWipeIn<1200>>>>(),
    StylePtr<Blinking<White,Black,500,500>>(),
    "0"},
  // Vader ANH
  { "Vader ANH;common", "tracks/Vader ANH.wav",
      StylePtr<Layers<
      AudioFlicker<RotateColorsX<Variation,Red>,RotateColorsX<Variation,Rgb<128,0,0>>>,
      TransitionEffectL<TrConcat<TrFade<400>,AudioFlickerL<RotateColorsX<Variation,Red>>,TrDelay<4999>,AudioFlickerL<RotateColorsX<Variation,Red>>,TrFade<800>>,EFFECT_FORCE>,
      EffectSequence<EFFECT_FORCE,AlphaL<AudioFlickerL<RotateColorsX<Variation,Red>>,SwingSpeed<300>>,AlphaL<White,Int<0>>>,

      //VaderOWK_ANH_Lockup
      LockupTrL<Layers<
        AlphaL<Blinking<Yellow,Strobe<Yellow,LemonChiffon,30,30>,60,500>,Bump<Scale<BladeAngle<5000,28000>,Scale<BladeAngle<8000,16000>,Int<3000>,Int<44000>>,Int<3000>>,Scale<SlowNoise<Int<3000>>,Int<8000>,Int<18000>>>>,
        AlphaL<Blinking<BrownNoiseFlicker<Yellow,LemonChiffon,50>,BrownNoiseFlicker<Yellow,Yellow,50>,100,500>,Bump<Scale<BladeAngle<5000,28000>,Scale<BladeAngle<8000,16000>,Int<3000>,Int<44000>>,Int<3000>>,Int<18000>>>>,TrConcat<TrInstant,AlphaL<Blinking<LemonChiffon,Strobe<BrownNoiseFlicker<LemonChiffon,LemonChiffon,500>,Yellow,15,30>,60,500>,Bump<Scale<BladeAngle<5000,28000>,Scale<BladeAngle<8000,16000>,Int<3000>,Int<44000>>,Int<3000>>,Scale<SlowNoise<Int<3000>>,Int<25000>,Int<32000>>>>,TrFade<300>>,TrSmoothFade<300>,SaberBase::LOCKUP_NORMAL>,
      TransitionEffectL<TrConcat<TrInstant,AlphaL<Strobe<LemonChiffon,LemonChiffon,20,30>,Bump<Scale<BladeAngle<5000,28000>,Scale<BladeAngle<8000,16000>,Int<3000>,Int<44000>>,Int<3000>>,Int<15000>>>,TrFade<300>>,EFFECT_LOCKUP_BEGIN>,
      TransitionEffectL<TrConcat<TrInstant,HumpFlickerL<Strobe<AlphaL<LemonChiffon,Int<20000>>,Yellow,20,30>,30>,TrSmoothFade<250>>,EFFECT_LOCKUP_BEGIN>,
      TransitionEffectL<TrConcat<TrInstant,LemonChiffon,TrDelay<25>>,EFFECT_LOCKUP_BEGIN>,
      TransitionEffectL<TrConcat<TrInstant,Strobe<Yellow,Yellow,20,30>,TrFade<200>,BrownNoiseFlickerL<AlphaL<Yellow,Int<16000>>,Int<50>>,TrJoinR<TrWipe<200>,TrWipeIn<200>,TrFade<200>>>,EFFECT_LOCKUP_END>,
      LockupTrL<AlphaL<White,LayerFunctions<Bump<Scale<SlowNoise<Int<2000>>,Int<3000>,Int<16000>>,Scale<BrownNoiseF<Int<10>>,Int<14000>,Int<8000>>>,Bump<Scale<SlowNoise<Int<2300>>,Int<26000>,Int<8000>>,Scale<NoisySoundLevel,Int<5000>,Int<10000>>>,Bump<Scale<SlowNoise<Int<2300>>,Int<20000>,Int<30000>>,Scale<IsLessThan<SlowNoise<Int<1500>>,Int<8000>>,Scale<NoisySoundLevel,Int<5000>,Int<0>>,Int<0>>>>>,TrConcat<TrInstant,AlphaL<White,Bump<Int<12000>,Int<18000>>>,TrFade<200>>,TrConcat<TrInstant,HumpFlickerL<AlphaL<White,Int<16000>>,30>,TrSmoothFade<600>>,SaberBase::LOCKUP_LIGHTNING_BLOCK>,
      AlphaL<Black,SmoothStep<Scale<SlowNoise<Int<1600>>,Int<1000>,Int<6000>>,Int<-6000>>>,
      //AlphaL<RotateColorsX<Variation,Rgb<25,0,0>>,Bump<Int<0>,Int<8000>>>,
      ResponsiveStabL<Orange>,
      EffectSequence<EFFECT_BLAST,ResponsiveBlastL<TransitionEffect<Rgb<255,240,80>,LemonChiffon,TrInstant,TrFade<50>,EFFECT_BLAST>,Int<400>,Scale<SwingSpeed<200>,Int<100>,Int<400>>>,Layers<ResponsiveBlastFadeL<TransitionEffect<Rgb<255,240,80>,LemonChiffon,TrInstant,TrFade<100>,EFFECT_BLAST>,Scale<SwingSpeed<200>,Int<10000>,Int<18000>>>,ResponsiveBlastFadeL<LemonChiffon,Scale<SwingSpeed<200>,Int<4000>,Int<10000>>>>,BlastL<TransitionEffect<Rgb<255,240,80>,LemonChiffon,TrInstant,TrFade<50>,EFFECT_BLAST>>,ResponsiveBlastL<TransitionEffect<Rgb<255,240,80>,LemonChiffon,TrInstant,TrFade<50>,EFFECT_BLAST>>>,BlastL<TransitionEffect<Rgb<255,240,80>,LemonChiffon,TrInstant,TrFade<50>,EFFECT_BLAST>>,
      TransitionEffectL<TrConcat<TrInstant,Yellow,TrDelay<25>,AlphaL<TransitionEffect<TransitionEffect<Strobe<LemonChiffon,GreenYellow,20,20>,BrownNoiseFlicker<Yellow,Rgb<108,192,6>,300>,TrInstant,TrFade<300>,EFFECT_CLASH>,LightYellow,TrInstant,TrDelay<150>,EFFECT_CLASH>,Bump<Scale<BladeAngle<>,Int<25000>,Int<8000>>,Int<18000>>>,TrFade<600>>,EFFECT_CLASH>,
      LockupTrL<AlphaL<BrownNoiseFlickerL<White,Int<300>>,SmoothStep<Int<30000>,Int<5000>>>,TrWipeIn<400>,TrFade<300>,SaberBase::LOCKUP_DRAG>,
      LockupTrL<AlphaL<Mix<TwistAngle<>,Rgb<255,200,0>,DarkOrange>,SmoothStep<Int<28000>,Int<5000>>>,TrWipeIn<600>,TrFade<300>,SaberBase::LOCKUP_MELT>,
      InOutTrL<TrWipe<850>,TrWipeIn<1060>>>>(),
    StylePtr<Blinking<White,Black,500,500>>(),
    "0"},
  // Luke Exile
  { "Luke Exile;common", "tracks/Luke Exile.wav",
    StylePtr<InOutHelper<OnSpark<Blast<LocalizedClash<Lockup<AudioFlicker<Green,Rgb16<0,38402,0>>,Pulsing<Gradient<AudioFlicker<Green,Rgb16<0,38402,0>>,AudioFlicker<Green,Rgb16<0,38402,0>>,HumpFlicker<OrangeRed,Pink,50>,AudioFlicker<Green,Rgb16<0,38402,0>>,AudioFlicker<Green,Rgb16<0,38402,0>>>,Gradient<AudioFlicker<Green,Rgb16<0,38402,0>>,AudioFlicker<Green,Rgb16<0,38402,0>>,HumpFlicker<OrangeRed,Pink,50>,AudioFlicker<Green,Rgb16<0,38402,0>>,AudioFlicker<Green,Rgb16<0,38402,0>>,AudioFlicker<Green,Rgb16<0,38402,0>>>,3500>,Gradient<AudioFlicker<Cyan,DeepSkyBlue>,AudioFlicker<Cyan,DeepSkyBlue>,HumpFlicker<Pink,OrangeRed,50>>>,Pink>,Pink>,Pink,400>,200,500>>(), 
    StylePtr<Blinking<White,Black,500,500>>(),"0"}, 
  // Vader R1
  { "Vader R1;common", "tracks/Vader R1.wav",
  StylePtr<Layers<
  HumpFlicker<RotateColorsX<Variation,Rgb<175,0,0>>,RotateColorsX<Variation,Rgb<75,0,0>>,75>,
  LockupTrL<Layers<
    AlphaL<Blinking<LightYellow,Strobe<Rgb<150,150,255>,LemonChiffon,15,30>,60,500>,Bump<Scale<BladeAngle<5000,28000>,Scale<BladeAngle<8000,16000>,Int<3000>,Int<44000>>,Int<3000>>,Scale<SlowNoise<Int<3000>>,Int<8000>,Int<18000>>>>,
    AlphaL<Blinking<BrownNoiseFlicker<LightYellow,Rgb<239,182,43>,50>,BrownNoiseFlicker<DarkOrange,Rgb<239,182,43>,50>,100,500>,Bump<Scale<BladeAngle<5000,28000>,Scale<BladeAngle<8000,16000>,Int<3000>,Int<44000>>,Int<3000>>,Int<16999>>>>,TrConcat<TrInstant,AlphaL<Blinking<Cornsilk,Strobe<BrownNoiseFlicker<LightYellow,Rgb<239,182,43>,500>,Black,15,30>,60,500>,Bump<Scale<BladeAngle<5000,28000>,Scale<BladeAngle<8000,16000>,Int<3000>,Int<44000>>,Int<3000>>,Scale<SlowNoise<Int<3000>>,Int<25000>,Int<32000>>>>,TrFade<300>>,TrSmoothFade<250>,SaberBase::LOCKUP_NORMAL>,
  TransitionEffectL<TrConcat<TrInstant,AlphaL<Strobe<LightYellow,Rgb<239,182,43>,20,30>,Bump<Scale<BladeAngle<5000,28000>,Scale<BladeAngle<8000,16000>,Int<3000>,Int<44000>>,Int<3000>>,Int<15000>>>,TrFade<300>>,EFFECT_LOCKUP_BEGIN>,
  TransitionEffectL<TrConcat<TrInstant,HumpFlickerL<Strobe<AlphaL<LightYellow,Int<20000>>,Black,20,30>,30>,TrSmoothFade<250>>,EFFECT_LOCKUP_BEGIN>,
  TransitionEffectL<TrConcat<TrInstant,Rgb<239,182,43>,TrDelay<25>>,EFFECT_LOCKUP_BEGIN>,
  TransitionEffectL<TrConcat<TrInstant,Strobe<LightYellow,Rgb<239,182,43>,15,1>,TrFade<200>,BrownNoiseFlickerL<AlphaL<Cornsilk,Int<16000>>,Int<50>>,TrJoinR<TrWipe<200>,TrWipeIn<200>,TrFade<300>>>,EFFECT_LOCKUP_END>,
  ResponsiveLightningBlockL<Strobe<Rgb<200,75,0>,AudioFlicker<White,White>,50,1>,TrConcat<TrInstant,AlphaL<Orange,Bump<Int<12000>,Int<18000>>>,TrFade<200>>,TrConcat<TrInstant,HumpFlickerL<AlphaL<White,Int<16000>>,30>,TrSmoothFade<600>>>,
  TransitionEffectL<TrConcat<TrInstant,Rgb<200,75,0>,TrDelay<25>,AlphaL<Black,Int<0>>,TrWipeIn<300>,AlphaL<Stripes<5000,1000,Rgb<128,8,0>,Rgb<180,0,0>,Rgb<128,0,0>,Rgb<80,0,0>,OrangeRed,DarkOrange>,SmoothStep<Int<25000>,Int<2000>>>,TrJoin<TrSmoothFade<900>,TrWipe<700>>>,EFFECT_STAB>,
  EffectSequence<EFFECT_BLAST,ResponsiveBlastL<TransitionEffect<Rgb<241,182,43>,Moccasin,TrInstant,TrFade<50>,EFFECT_BLAST>,Int<400>,Scale<SwingSpeed<200>,Int<100>,Int<400>>>,Layers<
    ResponsiveBlastFadeL<TransitionEffect<Rgb<255,150,0>,Moccasin,TrInstant,TrFade<100>,EFFECT_BLAST>,Scale<SwingSpeed<200>,Int<10000>,Int<18000>>>,
    ResponsiveBlastFadeL<Moccasin,Scale<SwingSpeed<200>,Int<4000>,Int<10000>>>>,BlastL<TransitionEffect<Rgb<255,150,0>,Moccasin,TrInstant,TrFade<50>,EFFECT_BLAST>>,ResponsiveBlastL<TransitionEffect<Rgb<255,150,0>,Moccasin,TrInstant,TrFade<50>,EFFECT_BLAST>>>,BlastL<TransitionEffect<Rgb<255,150,0>,Moccasin,TrInstant,TrFade<50>,EFFECT_BLAST>>,
  //FoC EP6 Version (Sparkling)
  ResponsiveClashL<Sparkle<Rgb<175,0,0>,LightYellow,9999,499>,TrInstant,TrFade<400>,Scale<BladeAngle<0,16000>,Int<10000>,Int<30000>>,Int<10000>,Int<20000>>,
  TransitionEffectL<TrConcat<TrInstant,HumpFlickerL<OrangeRed,15>,TrFade<800>>,EFFECT_IGNITION>,
  TransitionEffectL<TrConcat<TrInstant,HumpFlickerL<OrangeRed,15>,TrFade<1000>>,EFFECT_RETRACTION>,
  LockupTrL<AlphaL<Mix<TwistAngle<>,Stripes<1000,3000,White,Rgb<30,30,30>,White,Rgb<30,30,30>>,Stripes<2000,3000,White,Rgb<30,30,30>,White,Rgb<30,30,30>>>,SmoothStep<Scale<TwistAngle<>,Int<29000>,Int<26000>>,Int<5000>>>,TrWipeIn<600>,TrFade<300>,SaberBase::LOCKUP_DRAG>,
  LockupTrL<AlphaL<Mix<TwistAngle<>,Stripes<1000,3000,Yellow,OrangeRed,Rgb<50,50,0>,Orange>,Stripes<2000,3000,LemonChiffon,Orange,Tomato,Coral>>,SmoothStep<Scale<TwistAngle<>,Int<29000>,Int<26000>>,Int<5000>>>,TrWipeIn<600>,TrFade<300>,SaberBase::LOCKUP_MELT>,
  InOutTrL<TrWipe<700>,TrWipeIn<800>>>>(),
    StylePtr<Blinking<White,Black,500,500>>(),
    "0"},
  { "SentinelShan;common", "tracks/SentinelShan.wav",
    StylePtr<InOutHelper<OnSpark<Blast<LocalizedClash<Lockup<AudioFlicker<Blue,DodgerBlue>,Pulsing<Gradient<AudioFlicker<Blue,DodgerBlue>,AudioFlicker<Blue,DodgerBlue>,HumpFlicker<OrangeRed,Pink,50>,AudioFlicker<Blue,DodgerBlue>,AudioFlicker<Blue,DodgerBlue>>,Gradient<AudioFlicker<Blue,DodgerBlue>,AudioFlicker<Blue,DodgerBlue>,HumpFlicker<OrangeRed,Pink,50>,AudioFlicker<Blue,DodgerBlue>,AudioFlicker<Blue,DodgerBlue>,AudioFlicker<Blue,DodgerBlue>>,3500>,Gradient<AudioFlicker<Blue,DodgerBlue>,AudioFlicker<Blue,DodgerBlue>,HumpFlicker<Pink,OrangeRed,50>>>,Pink>,Pink>,Pink,400>,200,500>>(),
    StylePtr<Blinking<White,Black,500,500>>(), "0"}, 
  { "TheSecondSister;common", "tracks/TheSecondSister.wav",
    StylePtr<InOutHelper<OnSpark<Blast<LocalizedClash<Lockup<AudioFlicker<Rgb16<65535,0,50000>,Rgb16<65535,0,45000>>,Pulsing<Gradient<AudioFlicker<Rgb16<65535,0,50000>,Rgb16<65535,0,45000>>,AudioFlicker<Rgb16<65535,0,50000>,Rgb16<65535,0,45000>>,HumpFlicker<Green,Yellow,50>,AudioFlicker<Rgb16<65535,0,50000>,Rgb16<65535,0,45000>>,AudioFlicker<Rgb16<65535,0,50000>,Rgb16<65535,0,45000>>>,Gradient<AudioFlicker<Rgb16<65535,0,50000>,Rgb16<65535,0,45000>>,AudioFlicker<Rgb16<65535,0,50000>,Rgb16<65535,0,45000>>,HumpFlicker<Green,Yellow,50>,AudioFlicker<Rgb16<65535,0,50000>,Rgb16<65535,0,45000>>,AudioFlicker<Rgb16<65535,0,50000>,Rgb16<65535,0,45000>>,AudioFlicker<Rgb16<65535,0,50000>,Rgb16<65535,0,45000>>>,3500>,Gradient<AudioFlicker<Rgb16<65535,0,50000>,Rgb16<65535,0,45000>>,AudioFlicker<Rgb16<65535,0,50000>,Rgb16<65535,0,45000>>,HumpFlicker<Green,Cyan,50>>>>,White>,Pink,400>,200,500>>(),
    StylePtr<Blinking<White,Black,500,500>>(), "0"},  
  { "Graflex3;common", "tracks/Graflex3.wav",
    StylePtr<InOutHelper<OnSpark<Blast<LocalizedClash<Lockup<AudioFlicker<Blue,DodgerBlue>,Pulsing<Gradient<AudioFlicker<Blue,DodgerBlue>,AudioFlicker<Blue,DodgerBlue>,HumpFlicker<OrangeRed,Pink,50>,AudioFlicker<Blue,DodgerBlue>,AudioFlicker<Blue,DodgerBlue>>,Gradient<AudioFlicker<Blue,DodgerBlue>,AudioFlicker<Blue,DodgerBlue>,HumpFlicker<OrangeRed,Pink,50>,AudioFlicker<Blue,DodgerBlue>,AudioFlicker<Blue,DodgerBlue>,AudioFlicker<Blue,DodgerBlue>>,3500>,Gradient<AudioFlicker<Blue,DodgerBlue>,AudioFlicker<Blue,DodgerBlue>,HumpFlicker<Pink,OrangeRed,50>>>,Pink>,Pink>,Pink,400>,200,500>>(),
    StylePtr<Blinking<White,Black,500,500>>(), "0"},   
  { "Ahsoka;common", "tracks/Ahsoka.wav",
    StylePtr<InOutHelper<OnSpark<Blast<LocalizedClash<Lockup<AudioFlicker<Blue,DodgerBlue>,Pulsing<Gradient<AudioFlicker<Blue,DodgerBlue>,AudioFlicker<Blue,DodgerBlue>,HumpFlicker<OrangeRed,Pink,50>,AudioFlicker<Blue,DodgerBlue>,AudioFlicker<Blue,DodgerBlue>>,Gradient<AudioFlicker<Blue,DodgerBlue>,AudioFlicker<Blue,DodgerBlue>,HumpFlicker<OrangeRed,Pink,50>,AudioFlicker<Blue,DodgerBlue>,AudioFlicker<Blue,DodgerBlue>,AudioFlicker<Blue,DodgerBlue>>,3500>,Gradient<AudioFlicker<Blue,DodgerBlue>,AudioFlicker<Blue,DodgerBlue>,HumpFlicker<Pink,OrangeRed,50>>>,Pink>,Pink>,Pink,400>,200,500>>(),
    StylePtr<Blinking<White,Black,500,500>>(), "0"},  
  { "Yoda;common", "tracks/Yoda.wav",
    StylePtr<InOutHelper<OnSpark<Blast<LocalizedClash<Lockup<AudioFlicker<Green,Rgb16<0,38402,0>>,Pulsing<Gradient<AudioFlicker<Green,Rgb16<0,38402,0>>,AudioFlicker<Green,Rgb16<0,38402,0>>,HumpFlicker<OrangeRed,Pink,50>,AudioFlicker<Green,Rgb16<0,38402,0>>,AudioFlicker<Green,Rgb16<0,38402,0>>>,Gradient<AudioFlicker<Green,Rgb16<0,38402,0>>,AudioFlicker<Green,Rgb16<0,38402,0>>,HumpFlicker<OrangeRed,Pink,50>,AudioFlicker<Green,Rgb16<0,38402,0>>,AudioFlicker<Green,Rgb16<0,38402,0>>,AudioFlicker<Green,Rgb16<0,38402,0>>>,3500>,Gradient<AudioFlicker<Cyan,DeepSkyBlue>,AudioFlicker<Cyan,DeepSkyBlue>,HumpFlicker<Pink,OrangeRed,50>>>,Pink>,Pink>,Pink,400>,200,500>>(),
    StylePtr<Blinking<White,Black,500,500>>(), "0"},   
  { "ScavengersDestiny;common", "tracks/ScavengersDestiny.wav",
    StylePtr<IgnitionDelay<167,InOutHelper<OnSpark<Blast<LocalizedClash<Lockup<AudioFlicker<Rgb16<65535,38402,0>,Rgb16<47361,30457,0>>,Pulsing<Gradient<AudioFlicker<Rgb16<65535,38402,0>,Rgb16<47361,30457,0>>,AudioFlicker<Rgb16<65535,38402,0>,Rgb16<47361,30457,0>>,HumpFlicker<DeepSkyBlue,Cyan,50>,AudioFlicker<Rgb16<65535,38402,0>,Rgb16<47361,30457,0>>,AudioFlicker<Rgb16<65535,38402,0>,Rgb16<47361,30457,0>>>,Gradient<AudioFlicker<Rgb16<65535,38402,0>,Rgb16<47361,30457,0>>,AudioFlicker<Rgb16<65535,38402,0>,Rgb16<47361,30457,0>>,HumpFlicker<DeepSkyBlue,Cyan,50>,AudioFlicker<Rgb16<65535,38402,0>,Rgb16<47361,30457,0>>,AudioFlicker<Rgb16<65535,38402,0>,Rgb16<47361,30457,0>>,AudioFlicker<Rgb16<65535,38402,0>,Rgb16<47361,30457,0>>>,3500>,HumpFlicker<Cyan,LightCyan,50>>>,White>,Pink,400>,200,500>>>(),
    StylePtr<Blinking<White,Black,500,500>>(), "0"},   
  { "Maul;common", "tracks/Maul.wav",
    StylePtr<InOutHelper<OnSpark<Blast<LocalizedClash<Lockup<AudioFlicker<Red,Rgb16<38402,0,0>>,Gradient<AudioFlicker<Red,Rgb16<38402,0,0>>,AudioFlicker<Red,Rgb16<38402,0,0>>,HumpFlicker<Blue,Cyan,50>,AudioFlicker<Red,Rgb16<38402,0,0>>,AudioFlicker<Red,Rgb16<38402,0,0>>>,Gradient<AudioFlicker<Red,Rgb16<38402,0,0>>,AudioFlicker<Red,Rgb16<38402,0,0>>,HumpFlicker<Blue,Cyan,50>>>,Pink>,Pink>,Pink,400>,200,500>>(),
    StylePtr<Blinking<White,Black,500,500>>(), "0"},  
  { "QuiGone;common", "tracks/QuiGone.wav",
    StylePtr<InOutHelper<OnSpark<Blast<LocalizedClash<Lockup<AudioFlicker<Green,Rgb16<0,38402,0>>,Pulsing<Gradient<AudioFlicker<Green,Rgb16<0,38402,0>>,AudioFlicker<Green,Rgb16<0,38402,0>>,HumpFlicker<OrangeRed,Pink,50>,AudioFlicker<Green,Rgb16<0,38402,0>>,AudioFlicker<Green,Rgb16<0,38402,0>>>,Gradient<AudioFlicker<Green,Rgb16<0,38402,0>>,AudioFlicker<Green,Rgb16<0,38402,0>>,HumpFlicker<OrangeRed,Pink,50>,AudioFlicker<Green,Rgb16<0,38402,0>>,AudioFlicker<Green,Rgb16<0,38402,0>>,AudioFlicker<Green,Rgb16<0,38402,0>>>,3500>,Gradient<AudioFlicker<Cyan,DeepSkyBlue>,AudioFlicker<Cyan,DeepSkyBlue>,HumpFlicker<Pink,OrangeRed,50>>>,Pink>,Pink>,Pink,400>,200,500>>(),
    StylePtr<Blinking<White,Black,500,500>>(), "0"},  
  { "Obi4;common", "tracks/Obi4.wav",
    StylePtr<InOutHelper<OnSpark<Blast<LocalizedClash<Lockup<AudioFlicker<Blue,DodgerBlue>,Pulsing<Gradient<AudioFlicker<Blue,DodgerBlue>,AudioFlicker<Blue,DodgerBlue>,HumpFlicker<OrangeRed,Pink,50>,AudioFlicker<Blue,DodgerBlue>,AudioFlicker<Blue,DodgerBlue>>,Gradient<AudioFlicker<Blue,DodgerBlue>,AudioFlicker<Blue,DodgerBlue>,HumpFlicker<OrangeRed,Pink,50>,AudioFlicker<Blue,DodgerBlue>,AudioFlicker<Blue,DodgerBlue>,AudioFlicker<Blue,DodgerBlue>>,3500>,Gradient<AudioFlicker<Blue,DodgerBlue>,AudioFlicker<Blue,DodgerBlue>,HumpFlicker<Pink,OrangeRed,50>>>,Pink>,Pink>,Pink,400>,200,500>>(),
    StylePtr<Blinking<White,Black,500,500>>(), "0"},  
  { "Dooku;common", "tracks/Dooku.wav",
    StylePtr<InOutHelper<OnSpark<Blast<LocalizedClash<Lockup<AudioFlicker<Red,Rgb16<38402,0,0>>,Gradient<AudioFlicker<Red,Rgb16<38402,0,0>>,AudioFlicker<Red,Rgb16<38402,0,0>>,HumpFlicker<Blue,Cyan,50>,AudioFlicker<Red,Rgb16<38402,0,0>>,AudioFlicker<Red,Rgb16<38402,0,0>>>,Gradient<AudioFlicker<Red,Rgb16<38402,0,0>>,AudioFlicker<Red,Rgb16<38402,0,0>>,HumpFlicker<Blue,Cyan,50>>>,Pink>,Pink>,Pink,400>,200,500>>(),
    StylePtr<Blinking<White,Black,500,500>>(), "0"},  
  { "DV3;common", "tracks/DV3.wav",
    StylePtr<InOutHelper<OnSpark<Blast<LocalizedClash<Lockup<AudioFlicker<Red,Rgb16<38402,0,0>>,Gradient<AudioFlicker<Red,Rgb16<38402,0,0>>,AudioFlicker<Red,Rgb16<38402,0,0>>,HumpFlicker<Blue,Cyan,50>,AudioFlicker<Red,Rgb16<38402,0,0>>,AudioFlicker<Red,Rgb16<38402,0,0>>>,Gradient<AudioFlicker<Red,Rgb16<38402,0,0>>,AudioFlicker<Red,Rgb16<38402,0,0>>,HumpFlicker<Blue,Cyan,50>>>,Pink>,Pink>,Pink,400>,200,500>>(),
    StylePtr<Blinking<White,Black,500,500>>(), "0"},  
  { "DV6;common", "tracks/DV6.wav",
    StylePtr<InOutHelper<OnSpark<Blast<LocalizedClash<Lockup<AudioFlicker<Red,Rgb16<38402,0,0>>,Gradient<AudioFlicker<Red,Rgb16<38402,0,0>>,AudioFlicker<Red,Rgb16<38402,0,0>>,HumpFlicker<Blue,Cyan,50>,AudioFlicker<Red,Rgb16<38402,0,0>>,AudioFlicker<Red,Rgb16<38402,0,0>>>,Gradient<AudioFlicker<Red,Rgb16<38402,0,0>>,AudioFlicker<Red,Rgb16<38402,0,0>>,HumpFlicker<Blue,Cyan,50>>>,Pink>,Pink>,Pink,400>,200,500>>(),
    StylePtr<Blinking<White,Black,500,500>>(), "0"},  
  { "Emperor;common", "tracks/Emperor.wav",
    StylePtr<InOutHelper<OnSpark<Blast<LocalizedClash<Lockup<AudioFlicker<Red,Rgb16<38402,0,0>>,Gradient<AudioFlicker<Red,Rgb16<38402,0,0>>,AudioFlicker<Red,Rgb16<38402,0,0>>,HumpFlicker<Blue,Cyan,50>,AudioFlicker<Red,Rgb16<38402,0,0>>,AudioFlicker<Red,Rgb16<38402,0,0>>>,Gradient<AudioFlicker<Red,Rgb16<38402,0,0>>,AudioFlicker<Red,Rgb16<38402,0,0>>,HumpFlicker<Blue,Cyan,50>>>,Pink>,Pink>,Pink,400>,200,500>>(),
    StylePtr<Blinking<White,Black,500,500>>(), "0"},  
  { "GL9;common", "tracks/GL9.wav",
    StylePtr<InOutHelper<OnSpark<Blast<LocalizedClash<Lockup<AudioFlicker<Cyan,DeepSkyBlue>,Pulsing<Gradient<AudioFlicker<Cyan,DeepSkyBlue>,AudioFlicker<Cyan,DeepSkyBlue>,HumpFlicker<OrangeRed,Pink,50>,AudioFlicker<Cyan,DeepSkyBlue>,AudioFlicker<Cyan,DeepSkyBlue>>,Gradient<AudioFlicker<Cyan,DeepSkyBlue>,AudioFlicker<Cyan,DeepSkyBlue>,HumpFlicker<OrangeRed,Pink,50>,AudioFlicker<Cyan,DeepSkyBlue>,AudioFlicker<Cyan,DeepSkyBlue>,AudioFlicker<Cyan,DeepSkyBlue>>,3500>,Gradient<AudioFlicker<Cyan,DeepSkyBlue>,AudioFlicker<Cyan,DeepSkyBlue>,HumpFlicker<Pink,OrangeRed,50>>>,Pink>,Pink>,Pink,400>,200,500>>(),
    StylePtr<Blinking<White,Black,500,500>>(), "0"},  
  { "Ben;common", "tracks/Ben.wav",
    StylePtr<InOutHelper<OnSpark<Blast<LocalizedClash<Lockup<AudioFlicker<Cyan,DeepSkyBlue>,Pulsing<Gradient<AudioFlicker<Cyan,DeepSkyBlue>,AudioFlicker<Cyan,DeepSkyBlue>,HumpFlicker<OrangeRed,Pink,50>,AudioFlicker<Cyan,DeepSkyBlue>,AudioFlicker<Cyan,DeepSkyBlue>>,Gradient<AudioFlicker<Cyan,DeepSkyBlue>,AudioFlicker<Cyan,DeepSkyBlue>,HumpFlicker<OrangeRed,Pink,50>,AudioFlicker<Cyan,DeepSkyBlue>,AudioFlicker<Cyan,DeepSkyBlue>,AudioFlicker<Cyan,DeepSkyBlue>>,3500>,Gradient<AudioFlicker<Cyan,DeepSkyBlue>,AudioFlicker<Cyan,DeepSkyBlue>,HumpFlicker<Pink,OrangeRed,50>>>,Pink>,Pink>,Pink,400>,200,500>>(),
    StylePtr<Blinking<White,Black,500,500>>(), "0"},   
  { "Graflex4;common", "tracks/Graflex4.wav",
    StylePtr<InOutHelper<OnSpark<Blast<LocalizedClash<Lockup<AudioFlicker<Blue,DodgerBlue>,Pulsing<Gradient<AudioFlicker<Blue,DodgerBlue>,AudioFlicker<Blue,DodgerBlue>,HumpFlicker<OrangeRed,Pink,50>,AudioFlicker<Blue,DodgerBlue>,AudioFlicker<Blue,DodgerBlue>>,Gradient<AudioFlicker<Blue,DodgerBlue>,AudioFlicker<Blue,DodgerBlue>,HumpFlicker<OrangeRed,Pink,50>,AudioFlicker<Blue,DodgerBlue>,AudioFlicker<Blue,DodgerBlue>,AudioFlicker<Blue,DodgerBlue>>,3500>,Gradient<AudioFlicker<Blue,DodgerBlue>,AudioFlicker<Blue,DodgerBlue>,HumpFlicker<Pink,OrangeRed,50>>>,Pink>,Pink>,Pink,400>,200,500>>(),
    StylePtr<Blinking<White,Black,500,500>>(), "0"},  
  { "Graflex8;common", "tracks/Graflex8.wav",
    StylePtr<InOutHelper<OnSpark<Blast<LocalizedClash<Lockup<AudioFlicker<Cyan,DeepSkyBlue>,Pulsing<Gradient<AudioFlicker<Cyan,DeepSkyBlue>,AudioFlicker<Cyan,DeepSkyBlue>,HumpFlicker<OrangeRed,Pink,50>,AudioFlicker<Cyan,DeepSkyBlue>,AudioFlicker<Cyan,DeepSkyBlue>>,Gradient<AudioFlicker<Cyan,DeepSkyBlue>,AudioFlicker<Cyan,DeepSkyBlue>,HumpFlicker<OrangeRed,Pink,50>,AudioFlicker<Cyan,DeepSkyBlue>,AudioFlicker<Cyan,DeepSkyBlue>,AudioFlicker<Cyan,DeepSkyBlue>>,3500>,Gradient<AudioFlicker<Cyan,DeepSkyBlue>,AudioFlicker<Cyan,DeepSkyBlue>,HumpFlicker<Pink,OrangeRed,50>>>,Pink>,Pink>,Pink,400>,200,500>>(),
    StylePtr<Blinking<White,Black,500,500>>(), "0"},  
  { "KyloRenTLJ;common", "tracks/KyloRenTLJ.wav",
    StylePtr<InOutHelper<OnSpark<Blast<LocalizedClash<Lockup<HumpFlicker<DarkOrange,BrownNoiseFlicker<Red,Black,50>,15>,Gradient<HumpFlicker<DarkOrange,BrownNoiseFlicker<Red,Black,50>,15>,HumpFlicker<DarkOrange,BrownNoiseFlicker<Red,Black,50>,15>,HumpFlicker<Yellow,Green,50>,HumpFlicker<DarkOrange,BrownNoiseFlicker<Red,Black,50>,15>,HumpFlicker<DarkOrange,BrownNoiseFlicker<Red,Black,50>,15>>,Gradient<HumpFlicker<DarkOrange,BrownNoiseFlicker<Red,Black,50>,15>,HumpFlicker<DarkOrange,BrownNoiseFlicker<Red,Black,50>,15>,HumpFlicker<DarkOrange,BrownNoiseFlicker<Red,Black,50>,15>,HumpFlicker<Yellow,Green,50>>>,Pink>,Pink>,Pink,400>,200,500>>(),
    StylePtr<Blinking<White,Black,500,500>>(), "0"},  
  { "KyloRenTROS;common", "tracks/KyloRenTROS.wav",
    StylePtr<InOutHelper<OnSpark<Blast<LocalizedClash<Lockup<HumpFlicker<DarkOrange,BrownNoiseFlicker<Red,Black,50>,15>,Gradient<HumpFlicker<DarkOrange,BrownNoiseFlicker<Red,Black,50>,15>,HumpFlicker<DarkOrange,BrownNoiseFlicker<Red,Black,50>,15>,HumpFlicker<Yellow,Green,50>,HumpFlicker<DarkOrange,BrownNoiseFlicker<Red,Black,50>,15>,HumpFlicker<DarkOrange,BrownNoiseFlicker<Red,Black,50>,15>>,Gradient<HumpFlicker<DarkOrange,BrownNoiseFlicker<Red,Black,50>,15>,HumpFlicker<DarkOrange,BrownNoiseFlicker<Red,Black,50>,15>,HumpFlicker<DarkOrange,BrownNoiseFlicker<Red,Black,50>,15>,HumpFlicker<Yellow,Green,50>>>,Pink>,Pink>,Pink,400>,200,500>>(),
    StylePtr<Blinking<White,Black,500,500>>(), "0"},  
  { "CodeFulcrumAhsoka;common", "tracks/CodeFulcrumAhsoka.wav",
    StylePtr<InOutHelper<OnSpark<Blast<LocalizedClash<Lockup<AudioFlicker<White,Rgb16<38402,38402,38402>>,Gradient<AudioFlicker<White,Rgb16<38402,38402,38402>>,AudioFlicker<White,Rgb16<38402,38402,38402>>,HumpFlicker<Blue,Cyan,50>,AudioFlicker<White,Rgb16<38402,38402,38402>>,AudioFlicker<White,Rgb16<38402,38402,38402>>>,Gradient<AudioFlicker<White,Rgb16<38402,38402,38402>>,AudioFlicker<White,Rgb16<38402,38402,38402>>,HumpFlicker<Blue,Cyan,50>>>,Pink>,Pink>,Pink,400>,200,500>>(),
    StylePtr<Blinking<White,Black,500,500>>(), "0"},  
  { "DarkSaber;common", "tracks/DarkSaber.wav",
    StylePtr<InOutHelper<OnSpark<Blast<LocalizedClash<Lockup<AudioFlicker<White,Rgb16<38402,38402,38402>>,Gradient<AudioFlicker<White,Rgb16<38402,38402,38402>>,AudioFlicker<White,Rgb16<38402,38402,38402>>,HumpFlicker<Blue,Cyan,50>,AudioFlicker<White,Rgb16<38402,38402,38402>>,AudioFlicker<White,Rgb16<38402,38402,38402>>>,Gradient<AudioFlicker<White,Rgb16<38402,38402,38402>>,AudioFlicker<White,Rgb16<38402,38402,38402>>,HumpFlicker<Blue,Cyan,50>>>,Pink>,Pink>,Pink,400>,200,500>>(),
    StylePtr<Blinking<White,Black,500,500>>(), "0"}, 
  { "FoBlue;common", "tracks/FoBlue.wav",
    StylePtr<InOutHelper<OnSpark<Blast<LocalizedClash<Lockup<AudioFlicker<Blue,DodgerBlue>,Pulsing<Gradient<AudioFlicker<Blue,DodgerBlue>,AudioFlicker<Blue,DodgerBlue>,HumpFlicker<OrangeRed,Pink,50>,AudioFlicker<Blue,DodgerBlue>,AudioFlicker<Blue,DodgerBlue>>,Gradient<AudioFlicker<Blue,DodgerBlue>,AudioFlicker<Blue,DodgerBlue>,HumpFlicker<OrangeRed,Pink,50>,AudioFlicker<Blue,DodgerBlue>,AudioFlicker<Blue,DodgerBlue>,AudioFlicker<Blue,DodgerBlue>>,3500>,Gradient<AudioFlicker<Blue,DodgerBlue>,AudioFlicker<Blue,DodgerBlue>,HumpFlicker<Pink,OrangeRed,50>>>,Pink>,Pink>,Pink,400>,200,500>>(),
    StylePtr<Blinking<White,Black,500,500>>(), "0"},  
  { "FoRed;common", "tracks/FoRed.wav",
    StylePtr<InOutHelper<OnSpark<Blast<LocalizedClash<Lockup<AudioFlicker<Red,Rgb16<38402,0,0>>,Gradient<AudioFlicker<Red,Rgb16<38402,0,0>>,AudioFlicker<Red,Rgb16<38402,0,0>>,HumpFlicker<Blue,Cyan,50>,AudioFlicker<Red,Rgb16<38402,0,0>>,AudioFlicker<Red,Rgb16<38402,0,0>>>,Gradient<AudioFlicker<Red,Rgb16<38402,0,0>>,AudioFlicker<Red,Rgb16<38402,0,0>>,HumpFlicker<Blue,Cyan,50>>>,Pink>,Pink>,Pink,400>,200,500>>(),
    StylePtr<Blinking<White,Black,500,500>>(), "0"},  
  { "Metamorphose;common", "tracks/Metamorphose.wav",
    StylePtr<InOutHelper<OnSpark<Blast<LocalizedClash<Lockup<Gradient<Red,Blue,Green>,Gradient<Gradient<Red,Blue,Green>,Gradient<Red,Blue,Green>,AudioFlicker<White,Rgb16<20393,20393,20393>>,Gradient<Red,Blue,Green>,Gradient<Red,Blue,Green>>,HumpFlicker<Rgb16<20393,20393,20393>,White,50>>,Cyan>,Cyan>,Pink,400>,200,500>>(),
    StylePtr<Blinking<White,Black,500,500>>(), "0"},  
  { "Pikachu;common", "tracks/Pikachu.wav",
    StylePtr<InOutHelper<OnSpark<Blast<LocalizedClash<Lockup<HumpFlicker<Moccasin,BrownNoiseFlicker<Rgb16<65535,65535,20393>,Rgb16<37146,38402,110>,50>,15>,Gradient<HumpFlicker<Moccasin,BrownNoiseFlicker<Rgb16<65535,65535,20393>,Rgb16<37146,38402,110>,50>,15>,HumpFlicker<Moccasin,BrownNoiseFlicker<Rgb16<65535,65535,20393>,Rgb16<37146,38402,110>,50>,15>,HumpFlicker<LightCyan,SteelBlue,50>,HumpFlicker<Moccasin,BrownNoiseFlicker<Rgb16<65535,65535,20393>,Rgb16<37146,38402,110>,50>,15>,HumpFlicker<Moccasin,BrownNoiseFlicker<Rgb16<65535,65535,20393>,Rgb16<37146,38402,110>,50>,15>>,HumpFlicker<LightCyan,SteelBlue,50>>,Pink>,Pink>,Pink,400>,200,500>>(),
    StylePtr<Blinking<White,Black,500,500>>(), "0"},  
  { "ThunderGod;common", "tracks/ThunderGod.wav",
    StylePtr<Layers<StyleFire<Strobe<RotateColorsX<Variation,Rgb<95,0,210>>,Strobe<Rgb<100,100,150>,RandomPerLEDFlicker<RotateColorsX<Variation,Rgb<95,0,210>>,Black>,50,1>,100,1>,RotateColorsX<Variation,Rgb<23,0,65>>,0,5,FireConfig<2,1000,5>,FireConfig<2,1000,5>,FireConfig<2,1000,5>,FireConfig<2,1000,5>>,TransitionEffectL<TrConcat<TrInstant,BrownNoiseFlickerL<AlphaL<White,Int<16000>>,Int<50>>,TrSmoothFade<600>>,EFFECT_LOCKUP_END>,ResponsiveLockupL<Strobe<White,BrownNoiseFlicker<White,Red,300>,50,1>,TrConcat<TrInstant,White,TrFade<200>>,TrFade<400>,Scale<BladeAngle<0,16000>,Int<4000>,Int<26000>>,Int<6000>,Scale<SwingSpeed<100>,Int<10000>,Int<14000>>>,ResponsiveLightningBlockL<Strobe<White,AudioFlicker<White,Blue>,50,1>,TrConcat<TrInstant,AlphaL<White,Bump<Int<12000>,Int<18000>>>,TrFade<200>>,TrConcat<TrInstant,HumpFlickerL<AlphaL<White,Int<16000>>,30>,TrSmoothFade<600>>>,ResponsiveStabL<Red,TrWipeIn<600>,TrWipe<600>>,ResponsiveBlastL<White,Int<400>,Scale<SwingSpeed<200>,Int<100>,Int<400>>,Int<400>>,ResponsiveClashL<White,TrInstant,TrFade<400>,Scale<BladeAngle<0,16000>,Int<4000>,Int<26000>>,Int<6000>>,ResponsiveDragL<BrownNoiseFlickerL<White,Int<300>>,TrWipeIn<400>,TrFade<400>>,ResponsiveMeltL<Mix<TwistAngle<>,Red,Orange>,TrWipeIn<600>,TrSmoothFade<600>>,InOutTrL<TrWipe<300>,TrWipeIn<500>,Black>>>(),
    StylePtr<Blinking<White,Black,500,500>>(), "0"},  
  { "Fire;common", "tracks/Fire.wav",
    StyleFirePtr<Red, Yellow>(),
    StylePtr<Blinking<White,Black,500,500>>(), "0"},  
  { "Power;common", "tracks/Power.wav",
    &style_charging,
    StylePtr<Blinking<White,Black,500,500>>(), "0"},
};

BladeConfig blades[] = {
 { 0, WS281XBladePtr<144, bladePin, Color8::GRB, PowerPINS<bladePowerPin2, bladePowerPin3> >(),
    SimpleBladePtr<CreeXPE2WhiteTemplate<550>, NoLED, NoLED, NoLED, bladePowerPin6, -1, -1, -1>()
  , CONFIGARRAY(presets) },
};
#endif

#ifdef CONFIG_BUTTONS
Button PowerButton(BUTTON_POWER, powerButtonPin, "pow");
Button AuxButton(BUTTON_AUX, auxPin, "aux");
#endif

