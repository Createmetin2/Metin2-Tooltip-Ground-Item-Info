#Find
	def OnPressExitKey(self):
		self.interface.ToggleSystemDialog()
		return TRUE
		
#Add
	if app.TOOLTIP_GROUND_ITEM:
		def ShowItemFromClient(self, open, itemvnum = 0, metinslot = 0, attrtype = 0, attrval = 0):
			import uiToolTip
			pos_x, pos_y = wndMgr.GetMousePosition()
			self.tlground = uiToolTip.ItemToolTip()
			self.tlground.ClearToolTip()
			self.tlground.Hide()
			if open:
				attrSlot = []
				for i in xrange(player.ATTRIBUTE_SLOT_MAX_NUM):
					attrSlot.append([attrtype[i], attrval[i]])
				self.tlground.SetToolTipPosition(pos_x + 5, pos_y - 5)
				self.tlground.AddItemData(itemvnum, metinslot, attrSlot)