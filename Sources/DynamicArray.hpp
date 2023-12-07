#pragma once

#include "Common/types.hpp"

namespace stl {
	template <typename ValueType> class DynamicArray {
	public:
		DynamicArray() noexcept = default;
		DynamicArray(u64 const length) noexcept : m_Data{ new ValueType[length] }, m_Length{ length } {
		
		}
		DynamicArray(ValueType const& value, u64 const length) noexcept : m_Data{ new ValueType[length] }, m_Length{ length } {
			for (u64 i = 0; i < m_Length; ++i) { m_Data[i] = value; }
		}
		DynamicArray(DynamicArray const& data) noexcept : m_Data{ new ValueType[data.m_Length] }, m_Length{ data.m_Length } {
			for (u64 i = 0; i < m_Length; ++i) { m_Data[i] = data.m_Data[i]; }
		}
		DynamicArray(DynamicArray&& data) noexcept : m_Data{ data.m_Data }, m_Length{ data.m_Length } {
			data.m_Data = nullptr;
			data.m_Length = NULL;
		}
		~DynamicArray() noexcept {
			delete[] m_Data;
		}

		DynamicArray& operator= (DynamicArray const& data) noexcept {
			m_Data = new ValueType[data.m_Length];
			m_Length = data.m_Length;
			for (u64 i = 0; i < m_Length; ++i) { m_Data[i] = data.m_Data[i]; }
			return *this;
		}
		DynamicArray& operator= (DynamicArray&& data) noexcept {
			m_Data = data.m_Data;
			m_Length = data.m_Length;
			data.m_Data = nullptr;
			data.m_Length = NULL;
			return *this;
		}

		[[nodiscard]] ValueType& operator[] (u64 const index) noexcept { return m_Data[index]; }
		[[nodiscard]] ValueType const& operator[] (u64 const index) const noexcept { return m_Data[index]; }

		[[nodiscard]] ValueType* begin() noexcept { return m_Data; }
		[[nodiscard]] ValueType* end() noexcept { return m_Data + m_Length; }
		[[nodiscard]] ValueType const* const cbegin() const noexcept { return m_Data; }
		[[nodiscard]] ValueType const* const cend() const noexcept { return m_Data + m_Length; }
		[[nodiscard]] u64 size() const noexcept { return m_Length; }
		[[nodiscard]] ValueType* data() noexcept { return m_Data; }
		[[nodiscard]] ValueType const* const data() const noexcept { return m_Data; }

	private:
		ValueType* m_Data;
		u64 m_Length;
	};
}