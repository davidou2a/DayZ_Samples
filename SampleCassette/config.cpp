class CfgPatches
{
	class H2A_SampleCassette
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = 
		{
			"DZ_Data", 
			"DZ_Sounds_Effects",
			"H2A_HellRetexSurvival_Contents",
			"H2A_HellRetexSurvival_Scripts"
		};
	};
};

class CfgVehicles
{
	class Hell_K7;
	class Hell_K7_SampleCassette: Hell_K7
	{
		scope = 2;
		displayName = "Bensound - Ukulélé";
		descriptionShort = "From : https://www.bensound.com/royalty-free-music/track/ukulele";
	};
};


class CfgSoundShaders
{
	class Hell_K7_SoundShader;
	class Hell_K7_SampleCassette_SoundShader: Hell_K7_SoundShader
	{
		samples[]=
		{	
			{"H2A\DayZ_Samples\SampleCassette\sounds\bensound-ukulele",1}
		};
		volume=1.0;
	};		
};

class CfgSoundSets
{
	class Hell_K7_SampleCassette_SoundSet
	{
		soundShaders[]=
		{
			"Hell_K7_SampleCassette_SoundShader"
		};
	};
};

