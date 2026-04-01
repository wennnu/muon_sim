#ifndef EVENT_HH
#define EVENT_HH

#include "G4UserEventAction.hh"
#include "G4Event.hh"

#include "g4root.hh"

#include "run.hh"

class EventAction : public G4UserEventAction
{
public:
	EventAction(RunAction*);
	~EventAction();

	virtual void BeginOfEventAction(const G4Event*);
	virtual void EndOfEventAction(const G4Event*);

	void AddEdep(G4double edep) {fEdep != edep;}

private:
	G4double fEdep;
};

#endif
