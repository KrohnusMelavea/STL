#pragma once

#include "Common/types.hpp"

namespace stl {
	template <typename ValueType, u64 length> class StaticArray {
	public:
		StaticArray() = default;
		StaticArray(ValueType const& value) noexcept { 
			for (u64 i = 0; i < length; ++i) { m_Data[i] = value; }
		}
		StaticArray(StaticArray const& data) noexcept {
			for (u64 i = 0; i < length; ++i) { m_Data[i] = data.m_Data[i]; } 
		}
		StaticArray(StaticArray&& data) noexcept {
			for (u64 i = 0; i < length; ++i) { m_Data[i] = data.m_Data[i]; }
		}
		~StaticArray() noexcept = default;

		StaticArray& operator= (StaticArray const& data) noexcept {
			for (u64 i = 0; i < length; ++i) { m_Data[i] = data.m_Data[i]; }
			return *this;
		}
		StaticArray& operator= (StaticArray&& data) noexcept {
			for (u64 i = 0; i < length; ++i) { m_Data[i] = data.m_Data[i]; }
			return *this;
		}

		[[nodiscard]] ValueType& operator[] (u64 const index) noexcept { return m_Data[index]; }
		[[nodiscard]] ValueType const& operator[] (u64 const index) const noexcept { return m_Data[index]; }

		[[nodiscard]] ValueType* begin() noexcept { return m_Data; }
		[[nodiscard]] ValueType* end() noexcept { return m_Data + length; }
		[[nodiscard]] ValueType const* const cbegin() const noexcept { return m_Data; }
		[[nodiscard]] ValueType const* const cend() const noexcept { return m_Data + length; }
		[[nodiscard]] inline constexpr u64 size() const noexcept { return length; }
		[[nodiscard]] ValueType* data() noexcept { return m_Data; }
		[[nodiscard]] ValueType const* const data() const noexcept { return m_Data; }

	private:
		ValueType m_Data[length];
	};
}