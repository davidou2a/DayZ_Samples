/*modded class MissionServer
{
    override void InvokeOnConnect(PlayerBase player, PlayerIdentity identity)
    {
        super.InvokeOnConnect(player, identity);

        auto param = new Param2<string, string>("hello1", "hello2");
        GetGame().RPCSingleParam(player, Test_RPC.RPC_TEST, param, true, identity);
    }
}*/