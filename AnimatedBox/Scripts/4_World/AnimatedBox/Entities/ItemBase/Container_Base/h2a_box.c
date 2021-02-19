/**
 *  \file h2a_box.c
 *  
 *  \author Hellmaker2a <davidou2a@hotmail.com>
 *  \version 2020-06-22 22:06
 *  
 */
class H2A_Box : Container_Base
{
	private bool m_IsLocked = false;
	protected ref OpenableBehaviour m_Openable;
	
	/**
	 *  \name H2A_Box
	 *  
	 *  \return void
	 *  
	 *  \details none
	 */
	void H2A_Box()
	{
		m_Openable = new OpenableBehaviour( false );

		RegisterNetSyncVariableBool( "m_Openable.m_IsOpened" );
		RegisterNetSyncVariableBool( "m_IsSoundSynchRemote" );
	}
	
	/**
	 *  \name EEInit
	 *  
	 *  \return void
	 *  
	 *  \details none
	 */
	override void EEInit()
	{
		super.EEInit();
		//GetInventory().LockInventory( HIDE_INV_FROM_SCRIPT );
	}
	
	/**
	 *  \name IsLocked
	 *  
	 *  \return bool
	 *  
	 *  \details none
	 */
	bool IsLocked()
	{
		return m_IsLocked;
	}

	/**
	 *  \name Open
	 *  \brief Hide the cover "Top" and show the cover "Top2"
	 *  
	 *  \return void
	 *  
	 *  \details none
	 */
	override void Open()
	{
		m_Openable.Open();
		//GetInventory().UnlockInventory( HIDE_INV_FROM_SCRIPT );
		SoundSynchRemote();
		UpdateVisualState();
	}

	/**
	 *  \name Close
	 *  \brief Hide the cover "Top2" and show the cover "Top"
	 *  
	 *  \return void
	 *  
	 *  \details none
	 */
	override void Close()
	{
		m_Openable.Close();
		//GetInventory().LockInventory( HIDE_INV_FROM_SCRIPT );
		SoundSynchRemote();
		UpdateVisualState();
	}

	/**
	 *  \name IsOpen
	 *  
	 *  \return bool
	 *  
	 *  \details none
	 */
	override bool IsOpen()
	{
		return m_Openable.IsOpened();
	}

	/**
	 *  \name UpdateVisualState
	 *  
	 *  \return void
	 *  
	 *  \details none
	 */
	protected void UpdateVisualState()
	{
		if ( IsOpen() )
		{
			SetAnimationPhase( "Top",1 );
			SetAnimationPhase( "Top2",0 );
		}
		else
		{
			SetAnimationPhase( "Top",0 );
			SetAnimationPhase( "Top2",1 );
		}
	}

	/**
	 *  \name OnVariablesSynchronized
	 *  
	 *  \return void
	 *  
	 *  \details none
	 */
	override void OnVariablesSynchronized()
	{
		super.OnVariablesSynchronized();
				
		if ( IsOpen() && IsSoundSynchRemote() )
		{
			SoundBoxOpenPlay();
		}
		
		if ( !IsOpen() && IsSoundSynchRemote() )
		{
			SoundBoxClosePlay();
		}
		
		UpdateVisualState();
	}
	
	/**
	 *  \name SoundBoxOpenPlay
	 *  
	 *  \return void
	 *  
	 *  \details none
	 */
	void SoundBoxOpenPlay()
	{
		EffectSound sound =	SEffectManager.PlaySound( "barrel_open_SoundSet", GetPosition() );
		sound.SetSoundAutodestroy( true );
	}

	/**
	 *  \name Lock
	 *  
	 *  \param actiontime float
	 *  \return void
	 *  
	 *  \details none
	 */
	//void Lock( float actiontime )
	//{
	//	m_IsLocked = true;
	//	m_BarrelOpener.Run( actiontime, this, "Unlock", NULL,false );
	//}
	
	/**
	 *  \name Unlock
	 *  
	 *  \return void
	 *  
	 *  \details none
	 */
	//void Unlock()
	//{
	//	m_IsLocked = false;
	//	Open();
	//}
	
	/**
	 *  \name SoundBoxClosePlay
	 *  
	 *  \return void
	 *  
	 *  \details none
	 */
	void SoundBoxClosePlay()
	{
		EffectSound sound =	SEffectManager.PlaySound( "barrel_close_SoundSet", GetPosition() );
		sound.SetSoundAutodestroy( true );
	}
		
	/**
	 *  \name CanPutInCargo
	 *  
	 *  \param parent EntityAI
	 *  \return bool
	 *  
	 *  \details none
	 */
	override bool CanPutInCargo( EntityAI parent )
	{
		if( !super.CanPutInCargo(parent) ) { return false; }		
		if ( GetNumberOfItems() == 0 && !IsOpen() )
		{
			return true;
		}
		
		return false;
	}
	
	/**
	 *  \name CanPutIntoHands
	 *  
	 *  \param parent EntityAI
	 *  \return bool
	 *  
	 *  \details Aucun
	 */
	override bool CanPutIntoHands( EntityAI parent )
	{
		if( !super.CanPutIntoHands( parent ) )
		{
			return false;
		}
		
		if ( GetNumberOfItems() == 0 && !IsOpen() )
		{
			return true;
		}
		
		return false;
	}
	
	/**
	 *  \name CanReceiveItemIntoCargo
	 *  
	 *  \param cargo EntityAI
	 *  \return bool
	 *  
	 *  \details none
	 */
	override bool CanReceiveItemIntoCargo( EntityAI cargo )
	{
		return IsOpen();
	}
	
	/**
	 *  \name CanReleaseCargo
	 *  
	 *  \param attachment EntityAI
	 *  \return bool
	 *  
	 *  \details none
	 */
	override bool CanReleaseCargo( EntityAI attachment )
	{
		return IsOpen();
	}
	
	/**
	 *  \name SetActions
	 *  
	 *  \return void
	 *  
	 *  \details none
	 */
	override void SetActions()
	{
		super.SetActions();
		AddAction(ActionOpenBox);
		AddAction(ActionCloseBox);
	}
};
