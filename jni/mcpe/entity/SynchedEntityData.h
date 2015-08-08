#pragma once

// Size : 16
class SynchedEntityData
{
public:
	char filler1[16];
	
public:
	SynchedEntityData();
	SynchedEntityData(SynchedEntityData &&);
	~SynchedEntityData();
};
