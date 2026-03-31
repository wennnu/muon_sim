#ifndef CONSTRUCTION_HH
#define CONSTRUCTION_HH

#include "G4VUserDetectorConstruction.hh"
#include "G4VPhysicalVolume.hh"
#include "G4LogicalVolume.hh"
#include "G4PVPlacement.hh"
#include "G4Box.hh"
#include "G4Tubs.hh"
#include "G4NistManager.hh"
#include "G4SystemOfUnits.hh"
#include "G4Material.hh"

#include "detector.hh"

class MuonDetectorConstruction : public G4VUserDetectorConstruction
{
  public:
	// Notes: virtual function, function belongs to the child
	// so pointers will run the child function and not the
	// base function and it can be override by derived class
	// virtual function comes with a virtual destructor	
	MuonDetectorConstruction();
	~MuonDetectorConstruction();

	G4Tubs* MakeCylinder(G4String name,
		             G4double innerR,
			     G4double outerR,
        		     G4double height,
			     G4double startingAngle,
			     G4double spanningAngle);

	virtual G4VPhysicalVolume *Construct();
  private:
	G4LogicalVolume *logicDetector;
	virtual void ConstructSDandField();
};

#endif
