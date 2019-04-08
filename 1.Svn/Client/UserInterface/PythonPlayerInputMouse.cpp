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

//Find in : void CPythonPlayer::NEW_RefreshMouseWalkingDirection()
	switch (m_eReservedMode)
	{
		
///Add new case
		#ifdef TOOLTIP_GROUND_ITEM
		case MODE_CLICK_ITEM_RIGHT:
		{
			CPythonItem& rkIT=CPythonItem::Instance();

			TPixelPosition kPPosPickedItem;
			if (rkIT.GetGroundItemPosition(m_dwIIDReserved, &kPPosPickedItem))
			{
				if (pkInstMain->NEW_GetDistanceFromDestPixelPosition(kPPosPickedItem)<20.0f)
				{
					CPythonNetworkStream& rkNetStream=CPythonNetworkStream::Instance();

					TPixelPosition kPPosCur;
					pkInstMain->NEW_GetPixelPosition(&kPPosCur);

					float fCurRot=pkInstMain->GetRotation();
					rkNetStream.SendCharacterStatePacket(kPPosCur,  fCurRot, CInstanceBase::FUNC_WAIT, 0);
					SendClickItemPacket(m_dwIIDReserved, true);

					pkInstMain->NEW_Stop();

					__ClearReservedAction();
				}
				else
				{
					pkInstMain->NEW_MoveToDestPixelPositionDirection(kPPosPickedItem);
				}
			}
			else
			{
				__ClearReservedAction();
			}

			break;
		}
		#endif