//Find
bool CPythonPlayer::NEW_SetMouseState(int eMBT, int eMBS)
{
	if (eMBT>=MBT_NUM)
		return false;
	
///Add
#ifdef TOOLTIP_GROUND_ITEM
	ClickRight(eMBT);
#endif

///Add anywhere
#ifdef TOOLTIP_GROUND_ITEM
void CPythonPlayer::ClickRight(int eMBT)
{
	CInstanceBase* pkInstMain=NEW_GetMainActorPtr();
	if (!pkInstMain) return;
	DWORD dwPickedItemID;
	
	if (eMBT == MBT_RIGHT && __GetPickedItemID(&dwPickedItemID))
		__OnPressItem(*pkInstMain, dwPickedItemID, true);
	else
		PyCallClassMemberFunc(m_ppyGameWindow, "ShowItemFromClient", Py_BuildValue("(i)", FALSE));
}
#endif