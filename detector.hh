#ifndef DETECTOR_HH
#define DETECTOR_HH

#include "G4VSensitiveDetector.hh"
#include "G4RunManager.hh"

#include "G4AnalysisManager.hh"

// class for generate hits
class SensitiveDetector : public G4VSensitiveDetector
{
public:
	SensitiveDetector(G4String name);	  
	~SensitiveDetector();	  
private:
	virtual G4bool ProcessHits(G4Step *, G4TouchableHistory *);
};

#endif
