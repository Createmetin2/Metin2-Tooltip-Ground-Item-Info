//Find
bool CPythonPlayer::NEW_SetMouseState(int eMBT, int eMBS)
{
	if (eMBT>=MBT_NUM)
		return false;
	
///Add
#if defined(TOOLTIP_GROUND_ITEM)
	ClickRight(eMBT);
#endif

///Add anywhere
#if defined(TOOLTIP_GROUND_ITEM)
void CPythonPlayer::ClickRight(const int& eMBT)
{
	const auto pkInstMain(NEW_GetMainActorPtr());
	if (!pkInstMain) 
		return;
	DWORD dwPickedItemID;
	if (eMBT == MBT_RIGHT && __GetPickedItemID(&dwPickedItemID))
		__OnPressItem(*pkInstMain, dwPickedItemID, true);
	else
		PyCallClassMemberFunc(m_ppyGameWindow, "ShowItemFromClient", Py_BuildValue("(i)", FALSE));
}
#endif

//Find in : void CPythonPlayer::NEW_RefreshMouseWalkingDirection()
	switch (m_eReservedMode)
	{
		
///Add new case
#if defined(TOOLTIP_GROUND_ITEM)
		case MODE_CLICK_ITEM_RIGHT: {
			TPixelPosition kPPosPickedItem;
			if (CPythonItem::Instance().GetGroundItemPosition(m_dwIIDReserved, &kPPosPickedItem)) {
				if (pkInstMain->NEW_GetDistanceFromDestPixelPosition(kPPosPickedItem) < 250.0f) {
					TPixelPosition kPPosCur;
					pkInstMain->NEW_GetPixelPosition(&kPPosCur);
					CPythonNetworkStream::Instance().SendCharacterStatePacket(kPPosCur, pkInstMain->GetRotation(), CInstanceBase::FUNC_WAIT, 0);
					SendClickItemPacket(m_dwIIDReserved, true);
					pkInstMain->NEW_Stop();
					__ClearReservedAction();
				}
				else
					pkInstMain->NEW_MoveToDestPixelPositionDirection(kPPosPickedItem);
			}
			else
				__ClearReservedAction();
			break;
		}
#endif