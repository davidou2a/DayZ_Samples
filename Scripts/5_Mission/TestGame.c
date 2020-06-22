/*
class ETest
{
	void ETest() {}
	
	void ModifiyByRef(out int a, out int b, int c)
	{
		a = 1;
		b = 2;
		c = 3;
	}
}

modded class MissionGameplay
{
	ref ETest m_ETest = null;
	
    void MissionGameplay()
    {
		int a = 0;
		int b = 0;
		int c = 0;
		
		Print("*** DEBUG *** : a=" + a + " b=" + b + " c=" + c);
		
		m_ETest = new ref ETest();
		m_ETest.ModifiyByRef(a,b,c);
		
		Print("*** DEBUG *** : a=" + a + " b=" + b + " c=" + c);
    }
};
*/
