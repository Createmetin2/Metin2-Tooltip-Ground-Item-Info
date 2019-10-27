//Find
		typedef TTextTailMap					TChatTailMap;
		
///Add
#if defined(TOOLTIP_GROUND_ITEM)
		struct _TooltipInfo
		{
			std::vector<long> sockets;
			std::vector<TPlayerItemAttribute> attr;
		};
#endif

//Find
		void ShowItemTextTail(DWORD VirtualID);
		
///Add
#if defined(TOOLTIP_GROUND_ITEM)
		void RegisterItemToolTipInfo(unsigned long& id, const std::tuple<const std::vector<long>, const std::vector<TPlayerItemAttribute>>& tooltiptuple);
		bool GetSocketsAndAttr(unsigned long& id, std::vector<long>& soc, std::vector< TPlayerItemAttribute >& att);
#endif

//Find
		TChatTailMap				m_ChatTailMap;
		
///Add
#if defined(TOOLTIP_GROUND_ITEM)
		std::map<unsigned long, _TooltipInfo> ItemTooltipMap;
#endif