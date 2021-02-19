/**
 *  \file TestManager.c
 *  \author David BRIWA (Hellmaker2a) : https://github.com/davidou2a
 */

class TestManager
{
	PlayerBase 				m_Player;
	float					m_Number;
	
	/**
	 *  \name TestManager
	 *  
	 *  \param [in] player PlayerBase
	 *  \return void
	 */
	void TestManager(PlayerBase player) 
	{
		m_Player = player;
		
		if (GetGame().IsServer())
			m_Number = 1.0;
		
		if (GetGame().IsClient())
			m_Number = 0.0;
	}
	
	/**
	 *  \name SetNumber
	 *  
	 *  \param [in] f float
	 *  \return void
	 */
	void SetNumber(float f)
	{
		m_Number = f;
		ServerRequestSyncNumber();
	}
	
	/**
	 *  \name ServerRequestSyncNumber
	 *  
	 *  \return void
	 */
	void ServerRequestSyncNumber()
	{
		if (GetGame().IsServer())
		{
			ScriptJunctureData pCtx = new ScriptJunctureData;
			pCtx.Write(m_Number);
			m_Player.SendSyncJuncture(DayZPlayerSyncJunctures.SJ_TESTMANAGER_SERVER_REQUEST, pCtx);
		}
	}
	
	/**
	 *  \name ClientSendNumber
	 *  
	 *  \param [in] f float
	 *  \return void
	 */
	void ClientSendNumber(float f)
	{
		if (GetGame().IsClient())
		{
			m_Number = f;
			
			ScriptInputUserData ctx = new ScriptInputUserData;
				
			if (ctx.CanStoreInputUserData())
			{
				ctx.Write(DayZPlayerSyncJunctures.SJ_TESTMANAGER_CLIENT_REQUEST);
				ctx.Write(f);
				ctx.Send();
			}		
		}
	}	
	
	/**
	 *  \name Update
	 *  
	 *  \param [in] deltaT float
	 *  \return void
	 */
	void Update(float deltaT)
	{		
		if (GetGame().IsServer())
			Print("SERVER DEBUG : " + m_Number);
			
		if (GetGame().IsClient())
			Print("CLIENT DEBUG : " + m_Number);
	}
	
	/**
	 *  \name OnSyncJuncture
	 *  
	 *  \param [in] pJunctureID int
	 *  \param [in] pCtx        ParamsReadContext
	 *  \return void
	 */
	void OnSyncJuncture(int pJunctureID, ParamsReadContext pCtx)
	{
		switch (pJunctureID)
		{
			case DayZPlayerSyncJunctures.SJ_TESTMANAGER_SERVER_REQUEST:	
				float value;
			
				if ( !pCtx.Read(value) )
					return;
					
				m_Number = value;
				break;
		}
	}
	
	/**
	 *  \name OnInputUserDataProcess
	 *  
	 *  \param [in] userDataType int
	 *  \param [in] ctx          ParamsReadContext
	 *  \return bool
	 */
	bool OnInputUserDataProcess(int userDataType, ParamsReadContext ctx)
	{
		if (userDataType == DayZPlayerSyncJunctures.SJ_TESTMANAGER_CLIENT_REQUEST)
		{
			float f = 0.0;

			if (ctx.Read(f))
			{
				SetNumber(f);
			}
			return true;
		}
		return false;
	}
}