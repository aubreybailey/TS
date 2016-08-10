/* Copyright (C) 2011 Ion Torrent Systems, Inc. All Rights Reserved */
#include "IonVersion.h"

using namespace std;

string IonVersion::GetMajor()     {return "@ION_VERSION_MAJOR@";}
string IonVersion::GetMinor()     {return "@ION_VERSION_MINOR@";}
string IonVersion::GetRelease()   {return "@ION_VERSION_RELEASE@";}
string IonVersion::GetGitHash()   {return "@ION_VERSION_GITHASH@";}
string IonVersion::GetGitPath()   {return "@ION_VERSION_GITPATH@";}
string IonVersion::GetBuildNum()  {return "@ION_VERSION_BUILDNUM@";}
string IonVersion::GetBuildTag()  {return "@ION_VERSION_BUILDTAG@";}
string IonVersion::GetBuildHost() {return "@ION_VERSION_BUILDHOST@";}

string IonVersion::GetFullVersion(std::string module)
{
	string v = module;
	v += " (";
	v += "@ION_VERSION_MAJOR@";
	v += ".";
	v += "@ION_VERSION_MINOR@";
	v += ".";
	v += "@ION_VERSION_RELEASE@";
	v += ")\n";
	v += "Build: ";
	v += "@ION_VERSION_BUILDTAG@";
	v += " (";
	v += "@ION_VERSION_BUILDNUM@";
	v += ")\nSource: ";
	v += "@ION_VERSION_GITPATH@";
	v += " (";
	v += "@ION_VERSION_GITHASH@";
	v += ")\n";
	return v;
}

string IonVersion::GetVersion()
{
	string v = "@ION_VERSION_MAJOR@";
	v += ".";
	v += "@ION_VERSION_MINOR@";
   	return (v);
}



