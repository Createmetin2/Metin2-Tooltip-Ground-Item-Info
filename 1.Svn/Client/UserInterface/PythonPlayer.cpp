//Find in void CPythonPlayer::SendClickItemPacket(DWORD dwIID)
	if (dwCurTime >= s_dwNextTCPTime)
	{
		s_dwNextTCPTime=dwCurTime + 500;
		
///Add
#ifdef TOOLTIP_GROUND_ITEM
		if (rclick) 
		{
			CItemData * pItemData;
			if (!CItemManager::Instance().GetItemDataPointer(CPythonItem::Instance().GetVirtualNumberOfGroundItem(dwIID), &pItemData)) {
				Tracenf("CPythonPlayer::SendClickItemPacket(dwIID=%d) : Non-exist item.", dwIID);
				return;
			}
			PyObject *sockets = PyTuple_New(ITEM_SOCKET_SLOT_MAX_NUM);
			PyObject *attrtype = PyTuple_New(ITEM_ATTRIBUTE_SLOT_MAX_NUM);
			PyObject *attrval = PyTuple_New(ITEM_ATTRIBUTE_SLOT_MAX_NUM);
			for (auto i = 0; i < ITEM_SOCKET_SLOT_MAX_NUM; i++)
				PyTuple_SetItem(sockets, i, PyInt_FromLong(pItemData->GetSockets(i)));
			for (auto i = 0; i < ITEM_ATTRIBUTE_SLOT_MAX_NUM; i++) {
				PyTuple_SetItem(attrtype, i, PyInt_FromLong(pItemData->GetAttrType(i)));
				PyTuple_SetItem(attrval, i, PyInt_FromLong(pItemData->GetAttrVal(i)));
			}
			PyCallClassMemberFunc(m_ppyGameWindow, "ShowItemFromClient", Py_BuildValue("iiOOOi", TRUE, pItemData->GetTable()->dwVnum, sockets, attrtype, attrval, pItemData->GetItemId()));
			for (auto& del : { sockets, attrtype, attrval })
				Py_DECREF(del);
			return;
		}
#endif

//Find
void CPythonPlayer::SendClickItemPacket(DWORD dwIID)

///Change
#ifdef TOOLTIP_GROUND_ITEM
void CPythonPlayer::SendClickItemPacket(DWORD dwIID, bool rclick)
#else
void CPythonPlayer::SendClickItemPacket(DWORD dwIID)	
#endif