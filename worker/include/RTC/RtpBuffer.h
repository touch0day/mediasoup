#ifndef MS_RTC_RTP_BUFFER_H
#define MS_RTC_RTP_BUFFER_H

#include "common.h"
#include "RTC/RtpPacket.h"
#include <vector>
#include <list>

namespace RTC
{
	class RtpBuffer
	{
	private:
		struct StorageItem
		{
			uint8_t store[65536];
		};

	public:
		RtpBuffer(size_t size);
		~RtpBuffer();

		bool Add(RTC::RtpPacket* packet);

	private:
		std::vector<StorageItem> storage;
		typedef std::list<RTC::RtpPacket*> Packets;
		Packets packets;
	};
}

#endif