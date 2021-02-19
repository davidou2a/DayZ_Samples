/**
 *  \file actionconstructor.c
 *  
 *  \author Hellmaker2a <davidou2a@hotmail.com>
 *  \version 2020-06-22 22:06
 *  
 */
modded class ActionConstructor
{
	override void RegisterActions( TTypenameArray actions ) {
        actions.Insert( ActionCloseBox );
        actions.Insert( ActionOpenBox );
		
		super.RegisterActions( actions );
    }
}