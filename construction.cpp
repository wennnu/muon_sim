#include "construction.hh"

MuonDetectorConstruction::MuonDetectorConstruction()
{}

MuonDetectorConstruction::~MuonDetectorConstruction()
{}

G4Tubs* MuonDetectorConstruction::MakeCylinder(G4String name, G4double innerR,
					       G4double outerR, G4double height,
					       G4double startingAngle, G4double spanningAngle)
{
	G4Tubs* cylinder
	= new G4Tubs(name,
		     innerR,
		     outerR,
		     height,
		     startingAngle,
		     spanningAngle);	

	return cylinder;
}



G4VPhysicalVolume *MuonDetectorConstruction::Construct()
{
	G4NistManager *nist = G4NistManager::Instance();
	G4Material *air = nist->FindOrBuildMaterial("G4_AIR");	
	//G4Material *al = nist->FindOrBuildMaterial("G4_Al");	
	
	// creating the plastic scintillator material
	G4double z, a, density;
	G4int ncomponents, natoms;

	G4Element *C = nist->FindOrBuildElement("C");
	G4Element *H = nist->FindOrBuildElement("H");

	density = 1.032*g/cm3;	
	G4Material* PVT = new G4Material("polyvinyltoluene", density, ncomponents=2);
	PVT -> AddElement(C, natoms=9);
	PVT -> AddElement(H, natoms=10);

	G4double energy[2] = {1.239841939*eV/0.9, 1.239841939*eV/0.2};

	// optical properties of world filled with air
	G4double rindexWorld[2] = {1.0, 1.0};
	G4MaterialPropertiesTable *mptWorld = new G4MaterialPropertiesTable();
	mptWorld -> AddProperty("RINDEX", energy, rindexWorld, 2);
	air -> SetMaterialPropertiesTable(mptWorld);

	// optical properties of PVT
	G4double rindexPVT[2] = {1.58, 1.58};
	G4MaterialPropertiesTable *mptPVT = new G4MaterialPropertiesTable();
	mptPVT -> AddProperty("RINDEX", energy, rindexPVT, 2);
	PVT -> SetMaterialPropertiesTable(mptPVT);

	// create the world
	G4double length = 1.0*m;
	G4Box* worldBox = new G4Box("World", length, length, length);

	G4LogicalVolume* logicWorld = new G4LogicalVolume(worldBox, air, "World Air");
	G4VPhysicalVolume* physicalWorld = new G4PVPlacement(0, G4ThreeVector(0.,0.,0.), logicWorld, "Physical World",
							    0,
							    false,
							    0);

	// create the Al Cylinder Box
	G4Tubs* AlBoxDimension = MuonDetectorConstruction::MakeCylinder("Aluminum Dimension", 0.*cm,
									8.25*cm, 17.75*cm,
									0.*deg, 360.*deg);
	G4LogicalVolume* logicalAlBox = new G4LogicalVolume(AlBoxDimension, 
							air,
							"Aluminum Box");
	G4VPhysicalVolume* physicalAlBox = new G4PVPlacement(0, G4ThreeVector(0.,0.,0.),
							    logicalAlBox,
							    "AlBox",
							    logicWorld,
							    false,
							    0);
	
	// create the scintillator
	/*
	G4Tubs* scintillatorDimension = MuonDetectorConstruction::MakeCylinder("Scintillator Dimension", 0.*cm,
									7.5*cm, 6.25*cm,
									0.*deg, 360.*deg);

 
	G4LogicalVolume* logicPVT = new G4LogicalVolume(scintillatorDimension, PVT, "Plastic Scintillator"); 

	G4VPhysicalVolume* physicalPVT = new G4PVPlacement(0, G4ThreeVector(0., 0., -8.25*cm),
							logicPVT, // the logical volume inside
							"Muon Detector",
							logicWorld, // the logical volume outside
							false, // no boolean operations
							0); // its copy number

							*/
	return physicalWorld;
}

