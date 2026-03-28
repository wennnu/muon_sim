#ifndef GENERATOR_HH
#define GENERATOR_HH

#include "G4VUserPrimaryGeneratorAction.hh"
#include "G4Decay.hh"
#include "G4MuonDecayChannel.hh"
#include "G4SystemOfUnits.hh"
#include "G4ParticleTable.hh"
#include "G4ParticleGun.hh"

class PrimaryGenerator : public G4VUserPrimaryGeneratorAction
{
public:
	PrimaryGenerator();
	~PrimaryGenerator();

	virtual void GeneratePrimaries(G4Event*);

private:
	G4ParticleGun *fParticleGun;
};

#endif
