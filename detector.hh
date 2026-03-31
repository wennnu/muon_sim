#ifndef DETECTOR_HH
#define DETECTOR_HH

#include "G4VSensitiveDetector.hh"

class SensitiveDetector : public G4VSensitiveDetector
{
public:
	SensitiveDetector(G4String name);	  
	~SensitiveDetector();	  
private:
	virtual G4bool ProcessHits(G4Step *, G4TouchableHistory *);
};

#endif
