//Find
		void SetItemTableData(TItemTable * pItemTable);
		
///Add
#ifdef TOOLTIP_GROUND_ITEM
		void SetSocAttr(const std::vector<long>& socket, const std::vector<BYTE>& attrtypes, const std::vector<short>& attrvals);
		long GetSockets(int i) {return sockets[i];};
		BYTE GetAttrType(int i) {return attrtype[i];};
		short GetAttrVal(int i) {return attrval[i];};
#endif

//Find
		std::vector<std::string> m_strLODModelFileNameVector;
		
///Add
#ifdef TOOLTIP_GROUND_ITEM
		std::vector<long> sockets;
		std::vector<BYTE> attrtype;
		std::vector<short> attrval;
#endif