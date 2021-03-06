/**
 *  \file actionopenbox.c
 *  
 *  \author Hellmaker2a <davidou2a@hotmail.com>
 *  \version 2020-06-22 22:06
 *  
 */
class ActionOpenBox: ActionInteractBase
{
	void ActionOpenBox()
	{
		m_CommandUID 	= DayZPlayerConstants.CMD_ACTIONMOD_INTERACTONCE;
		m_StanceMask 	= DayZPlayerConstants.STANCEMASK_ERECT | DayZPlayerConstants.STANCEMASK_CROUCH;
		m_HUDCursorIcon = CursorIcons.OpenHood;
	}

	/**
	 *  \name GetText
	 *  
	 *  \return string
	 *  
	 *  \details none
	 */
	override string GetText()
	{
		return "#open";
	}

	/**
	 *  \name ActionCondition
	 *  
	 *  \param player PlayerBase
	 *  \param target ActionTarget
	 *  \param item ItemBase
	 *  \return bool
	 *  
	 *  \details none
	 */
	override bool ActionCondition( PlayerBase player, ActionTarget target, ItemBase item )
	{
		Object target_object = target.GetObject();
		
		if ( target_object.IsItemBase() )
		{
			H2A_Box ntarget = H2A_Box.Cast( target_object );
			
			if( ntarget )
			{
				if( !ntarget.IsLocked() && !ntarget.IsOpen() )
				{
					return true;
				}
			}
		}
		
		return false;
	}

	/**
	 *  \name OnExecuteServer
	 *  
	 *  \param action_data ActionData
	 *  \return void
	 *  
	 *  \details none
	 */
	override void OnExecuteServer( ActionData action_data )
	{
		Object target_object = action_data.m_Target.GetObject();
		H2A_Box ntarget = H2A_Box.Cast( target_object );
		
		if( ntarget )
		{
			ntarget.Open();
		}
	}
	
	/**
	 *  \name OnEndServer
	 *  
	 *  \param action_data ActionData
	 *  \return void
	 *  
	 *  \details none
	 */
	override void OnEndServer( ActionData action_data )
	{
		Object target_object = action_data.m_Target.GetObject();
		H2A_Box ntarget = H2A_Box.Cast( target_object );
		
		if( ntarget )
		{
			ntarget.SoundSynchRemoteReset();
		}
	}
}