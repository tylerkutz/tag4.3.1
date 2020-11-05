// G4 headers
#include "G4Poisson.hh"
#include "Randomize.hh"

// gemc headers
#include "ecs_hitprocess.h"

static ecsConstants initializeECSConstants(int runno)
{
	ecsConstants ecc;
	if(runno == -1) return ecc;
	
	
	ecc.runNo = 0;
	
	ecc.attlen              = 3760.; // Attenuation Length (mm)
	ecc.TDC_time_to_channel = 20.;   // conversion from time (ns) to TDC channels.
	ecc.ECfactor            = 3.5;   // number of p.e. divided by the energy deposited in MeV; value taken from gsim. see EC NIM paper table 1.
	ecc.TDC_MAX             = 4095;  // max value for EC tdc.
	ecc.ec_MeV_to_channel   = 10.;   // conversion from energy (MeV) to ADC channels
	
	return ecc;
}


// Process the ID and hit for the EC using individual EC scintillator strips.
map<string, double> ecs_HitProcess :: integrateDgt(MHit* aHit, int hitn)
{
	map<string, double> dgtz;
	if(aHit->isBackgroundHit == 1) return dgtz;
	
	vector<identifier> identity = aHit->GetId();
	
	// get sector, stack (inner or outer), view (U, V, W), and strip.
	int sector = identity[0].id;
	int stack  = identity[1].id;
	int view   = identity[2].id;
	int strip  = identity[3].id;
	trueInfos tInfos(aHit);
	
	// initialize ADC and TDC
	int ADC = 0;
	int TDC = ecc.TDC_MAX;
	
	// simulate the adc value.
	if (tInfos.eTot > 0)
	{
		// number of photoelectrons.
		double EC_npe = G4Poisson(tInfos.eTot*ecc.ECfactor);
		//  Fluctuations in PMT gain distributed using Gaussian with
		//  sigma SNR = sqrt(ngamma)/sqrt(del/del-1) del = dynode gain = 3 (From RCA PMT Handbook) p. 169)
		//  algorithm, values, and comment above taken from gsim.
		double sigma = sqrt(EC_npe)*1.15;
		double EC_charge = G4RandGauss::shoot(EC_npe,sigma)*ecc.ec_MeV_to_channel/ecc.ECfactor;
		if (EC_charge <= 0) EC_charge=0.0; // guard against weird, rare events.
		ADC = (int) EC_charge;
	}
	
	// simulate the tdc.
	TDC = (int) (tInfos.time*ecc.TDC_time_to_channel);
	if (TDC > ecc.TDC_MAX) TDC = ecc.TDC_MAX;
	
	dgtz["hitn"]   = hitn;
	dgtz["sector"] = sector;
	dgtz["stack"]  = stack;
	dgtz["view"]   = view;
	dgtz["strip"]  = strip;
	dgtz["ADC"]    = ADC;
	dgtz["TDC"]    = TDC;
	
	// decide if write an hit or not
	writeHit = true;
	// define conditions to reject hit
	if(rejectHitConditions) {
		writeHit = false;
	}
	
	return dgtz;
}

vector<identifier>  ecs_HitProcess :: processID(vector<identifier> id, G4Step* aStep, detector Detector)
{
	id[id.size()-1].id_sharing = 1;
	return id;
}


map< string, vector <int> >  ecs_HitProcess :: multiDgt(MHit* aHit, int hitn)
{
	map< string, vector <int> > MH;
	
	return MH;
}


// - charge: returns charge/time digitized information / step
map< int, vector <double> > ecs_HitProcess :: chargeTime(MHit* aHit, int hitn)
{
	map< int, vector <double> >  CT;
	
	return CT;
}

// - voltage: returns a voltage value for a given time. The inputs are:
// charge value (coming from chargeAtElectronics)
// time (coming from timeAtElectronics)
double ecs_HitProcess :: voltage(double charge, double time, double forTime)
{
	return 0.0;
}


// - electronicNoise: returns a vector of hits generated / by electronics.
vector<MHit*> ecs_HitProcess :: electronicNoise()
{
	vector<MHit*> noiseHits;
	
	// first, identify the cells that would have electronic noise
	// then instantiate hit with energy E, time T, identifier IDF:
	//
	// MHit* thisNoiseHit = new MHit(E, T, IDF, pid);
	
	// push to noiseHits collection:
	// noiseHits.push_back(thisNoiseHit)
	
	return noiseHits;
}

void ecs_HitProcess::initWithRunNumber(int runno)
{
	if(ecc.runNo != runno)
	{
		cout << " > Initializing " << HCname << " digitization for run number " << runno << endl;
		ecc = initializeECSConstants(runno);
		ecc.runNo = runno;
	}
}

// this static function will be loaded first thing by the executable
ecsConstants ecs_HitProcess::ecc = initializeECSConstants(-1);











