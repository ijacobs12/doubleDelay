/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"
#include "Oscillator.h"
#include "FractionalDelayBuffer.h"

//==============================================================================
/**
*/
class A_chorus_linesAudioProcessor  : public AudioProcessor
{
public:
    //==============================================================================
    A_chorus_linesAudioProcessor();
    ~A_chorus_linesAudioProcessor();

    //==============================================================================
    void prepareToPlay (double sampleRate, int samplesPerBlock) override;
    void releaseResources() override;

   #ifndef JucePlugin_PreferredChannelConfigurations
    bool isBusesLayoutSupported (const BusesLayout& layouts) const override;
   #endif

    void processBlock (AudioBuffer<float>&, MidiBuffer&) override;

    //==============================================================================
    AudioProcessorEditor* createEditor() override;
    bool hasEditor() const override;

    //==============================================================================
    const String getName() const override;

    bool acceptsMidi() const override;
    bool producesMidi() const override;
    bool isMidiEffect() const override;
    double getTailLengthSeconds() const override;

    //==============================================================================
    int getNumPrograms() override;
    int getCurrentProgram() override;
    void setCurrentProgram (int index) override;
    const String getProgramName (int index) override;
    void changeProgramName (int index, const String& newName) override;

    //==============================================================================
    void getStateInformation (MemoryBlock& destData) override;
    void setStateInformation (const void* data, int sizeInBytes) override;
    float get_Parameter(int index);
    void set_Parameter(int index, float newValue);
    enum Parameters
    {
        mixParam,
        widthParam,
        rateParam,
        totalNumParams
    };
private:
    Oscillator osc1;
    FractionalDelayBuffer leftBuffer1, rightBuffer1;
    float parameters[3];
    float leftDelayTime, rightDelayTime;
    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (A_chorus_linesAudioProcessor)
};
