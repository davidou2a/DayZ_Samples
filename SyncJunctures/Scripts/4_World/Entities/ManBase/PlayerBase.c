/**
 *  \file PlayerBase.c
 *  \author David BRIWA (Hellmaker2a) : https://github.com/davidou2a
 */
 
modded class PlayerBase
{
	ref TestManager m_TestManager;
	
	/**
	 *  \name Init
	 *  
	 *  \return void
	 */
	override void Init()
	{
		super.Init();
		m_TestManager = new TestManager(this);
				
		ScriptCallQueue queue = GetGame().GetCallQueue(CALL_CATEGORY_SYSTEM); 

		queue.CallLater(m_TestManager.SetNumber, 10000, false, 666.0);
		queue.CallLater(m_TestManager.ClientSendNumber, 20000, false, 20.0);
	}
	
	/**
	 *  \name CommandHandler
	 *  
	 *  \param [in] pDt                     float
	 *  \param [in] pCurrentCommandID       int
	 *  \param [in] pCurrentCommandFinished bool
	 *  \return void
	 */
	override void CommandHandler(float pDt, int pCurrentCommandID, bool pCurrentCommandFinished)	
	{
		super.CommandHandler(pDt,pCurrentCommandID,pCurrentCommandFinished);

		if (m_TestManager) 
			m_TestManager.Update(pDt);
	}
	
	/**
	 *  \name OnSyncJuncture
	 *  
	 *  \param [in] pJunctureID int
	 *  \param [in] pCtx        ParamsReadContext
	 *  \return void
	 */
	override void OnSyncJuncture(int pJunctureID, ParamsReadContext pCtx)
	{
		super.OnSyncJuncture(pJunctureID, pCtx);
		m_TestManager.OnSyncJuncture(pJunctureID, pCtx);
	}
	
	/**
	 *  \name OnInputUserDataProcess
	 *  
	 *  \param [in] userDataType int
	 *  \param [in] ctx          ParamsReadContext
	 *  \return bool
	 */
	override bool OnInputUserDataProcess(int userDataType, ParamsReadContext ctx)
	{
		if (super.OnInputUserDataProcess(userDataType, ctx))
			return true;
		
		if (m_TestManager.OnInputUserDataProcess(userDataType, ctx))
			return true;
			
		return false;
	}
}