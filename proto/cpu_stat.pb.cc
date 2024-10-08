// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: cpu_stat.proto

#include "cpu_stat.pb.h"

#include <algorithm>

#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/extension_set.h>
#include <google/protobuf/wire_format_lite.h>
#include <google/protobuf/descriptor.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/reflection_ops.h>
#include <google/protobuf/wire_format.h>
// @@protoc_insertion_point(includes)
#include <google/protobuf/port_def.inc>
namespace monitor {
namespace proto {
class CpuStatDefaultTypeInternal {
 public:
  ::PROTOBUF_NAMESPACE_ID::internal::ExplicitlyConstructed<CpuStat> _instance;
} _CpuStat_default_instance_;
}  // namespace proto
}  // namespace monitor
static void InitDefaultsscc_info_CpuStat_cpu_5fstat_2eproto() {
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  {
    void* ptr = &::monitor::proto::_CpuStat_default_instance_;
    new (ptr) ::monitor::proto::CpuStat();
    ::PROTOBUF_NAMESPACE_ID::internal::OnShutdownDestroyMessage(ptr);
  }
  ::monitor::proto::CpuStat::InitAsDefaultInstance();
}

::PROTOBUF_NAMESPACE_ID::internal::SCCInfo<0> scc_info_CpuStat_cpu_5fstat_2eproto =
    {{ATOMIC_VAR_INIT(::PROTOBUF_NAMESPACE_ID::internal::SCCInfoBase::kUninitialized), 0, 0, InitDefaultsscc_info_CpuStat_cpu_5fstat_2eproto}, {}};

static ::PROTOBUF_NAMESPACE_ID::Metadata file_level_metadata_cpu_5fstat_2eproto[1];
static constexpr ::PROTOBUF_NAMESPACE_ID::EnumDescriptor const** file_level_enum_descriptors_cpu_5fstat_2eproto = nullptr;
static constexpr ::PROTOBUF_NAMESPACE_ID::ServiceDescriptor const** file_level_service_descriptors_cpu_5fstat_2eproto = nullptr;

const ::PROTOBUF_NAMESPACE_ID::uint32 TableStruct_cpu_5fstat_2eproto::offsets[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  ~0u,  // no _has_bits_
  PROTOBUF_FIELD_OFFSET(::monitor::proto::CpuStat, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  PROTOBUF_FIELD_OFFSET(::monitor::proto::CpuStat, cpu_name_),
  PROTOBUF_FIELD_OFFSET(::monitor::proto::CpuStat, cpu_precent_),
  PROTOBUF_FIELD_OFFSET(::monitor::proto::CpuStat, user_precent_),
  PROTOBUF_FIELD_OFFSET(::monitor::proto::CpuStat, system_precent_),
  PROTOBUF_FIELD_OFFSET(::monitor::proto::CpuStat, nice_precent_),
  PROTOBUF_FIELD_OFFSET(::monitor::proto::CpuStat, idle_precent_),
  PROTOBUF_FIELD_OFFSET(::monitor::proto::CpuStat, iowait_precent_),
  PROTOBUF_FIELD_OFFSET(::monitor::proto::CpuStat, irq_precent_),
  PROTOBUF_FIELD_OFFSET(::monitor::proto::CpuStat, softirp_precent_),
};
static const ::PROTOBUF_NAMESPACE_ID::internal::MigrationSchema schemas[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  { 0, -1, sizeof(::monitor::proto::CpuStat)},
};

static ::PROTOBUF_NAMESPACE_ID::Message const * const file_default_instances[] = {
  reinterpret_cast<const ::PROTOBUF_NAMESPACE_ID::Message*>(&::monitor::proto::_CpuStat_default_instance_),
};

const char descriptor_table_protodef_cpu_5fstat_2eproto[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) =
  "\n\016cpu_stat.proto\022\rmonitor.proto\"\320\001\n\007CpuS"
  "tat\022\020\n\010cpu_name\030\001 \001(\t\022\023\n\013cpu_precent\030\002 \001"
  "(\002\022\024\n\014user_precent\030\003 \001(\002\022\026\n\016system_prece"
  "nt\030\005 \001(\002\022\024\n\014nice_precent\030\006 \001(\002\022\024\n\014idle_p"
  "recent\030\007 \001(\002\022\026\n\016iowait_precent\030\010 \001(\002\022\023\n\013"
  "irq_precent\030\t \001(\002\022\027\n\017softirp_precent\030\n \001"
  "(\002b\006proto3"
  ;
static const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable*const descriptor_table_cpu_5fstat_2eproto_deps[1] = {
};
static ::PROTOBUF_NAMESPACE_ID::internal::SCCInfoBase*const descriptor_table_cpu_5fstat_2eproto_sccs[1] = {
  &scc_info_CpuStat_cpu_5fstat_2eproto.base,
};
static ::PROTOBUF_NAMESPACE_ID::internal::once_flag descriptor_table_cpu_5fstat_2eproto_once;
static bool descriptor_table_cpu_5fstat_2eproto_initialized = false;
const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable descriptor_table_cpu_5fstat_2eproto = {
  &descriptor_table_cpu_5fstat_2eproto_initialized, descriptor_table_protodef_cpu_5fstat_2eproto, "cpu_stat.proto", 250,
  &descriptor_table_cpu_5fstat_2eproto_once, descriptor_table_cpu_5fstat_2eproto_sccs, descriptor_table_cpu_5fstat_2eproto_deps, 1, 0,
  schemas, file_default_instances, TableStruct_cpu_5fstat_2eproto::offsets,
  file_level_metadata_cpu_5fstat_2eproto, 1, file_level_enum_descriptors_cpu_5fstat_2eproto, file_level_service_descriptors_cpu_5fstat_2eproto,
};

// Force running AddDescriptors() at dynamic initialization time.
static bool dynamic_init_dummy_cpu_5fstat_2eproto = (  ::PROTOBUF_NAMESPACE_ID::internal::AddDescriptors(&descriptor_table_cpu_5fstat_2eproto), true);
namespace monitor {
namespace proto {

// ===================================================================

void CpuStat::InitAsDefaultInstance() {
}
class CpuStat::_Internal {
 public:
};

CpuStat::CpuStat()
  : ::PROTOBUF_NAMESPACE_ID::Message(), _internal_metadata_(nullptr) {
  SharedCtor();
  // @@protoc_insertion_point(constructor:monitor.proto.CpuStat)
}
CpuStat::CpuStat(const CpuStat& from)
  : ::PROTOBUF_NAMESPACE_ID::Message(),
      _internal_metadata_(nullptr) {
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  cpu_name_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  if (!from._internal_cpu_name().empty()) {
    cpu_name_.AssignWithDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), from.cpu_name_);
  }
  ::memcpy(&cpu_precent_, &from.cpu_precent_,
    static_cast<size_t>(reinterpret_cast<char*>(&softirp_precent_) -
    reinterpret_cast<char*>(&cpu_precent_)) + sizeof(softirp_precent_));
  // @@protoc_insertion_point(copy_constructor:monitor.proto.CpuStat)
}

void CpuStat::SharedCtor() {
  ::PROTOBUF_NAMESPACE_ID::internal::InitSCC(&scc_info_CpuStat_cpu_5fstat_2eproto.base);
  cpu_name_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  ::memset(&cpu_precent_, 0, static_cast<size_t>(
      reinterpret_cast<char*>(&softirp_precent_) -
      reinterpret_cast<char*>(&cpu_precent_)) + sizeof(softirp_precent_));
}

CpuStat::~CpuStat() {
  // @@protoc_insertion_point(destructor:monitor.proto.CpuStat)
  SharedDtor();
}

void CpuStat::SharedDtor() {
  cpu_name_.DestroyNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
}

void CpuStat::SetCachedSize(int size) const {
  _cached_size_.Set(size);
}
const CpuStat& CpuStat::default_instance() {
  ::PROTOBUF_NAMESPACE_ID::internal::InitSCC(&::scc_info_CpuStat_cpu_5fstat_2eproto.base);
  return *internal_default_instance();
}


void CpuStat::Clear() {
// @@protoc_insertion_point(message_clear_start:monitor.proto.CpuStat)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  cpu_name_.ClearToEmptyNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  ::memset(&cpu_precent_, 0, static_cast<size_t>(
      reinterpret_cast<char*>(&softirp_precent_) -
      reinterpret_cast<char*>(&cpu_precent_)) + sizeof(softirp_precent_));
  _internal_metadata_.Clear();
}

const char* CpuStat::_InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) {
#define CHK_(x) if (PROTOBUF_PREDICT_FALSE(!(x))) goto failure
  while (!ctx->Done(&ptr)) {
    ::PROTOBUF_NAMESPACE_ID::uint32 tag;
    ptr = ::PROTOBUF_NAMESPACE_ID::internal::ReadTag(ptr, &tag);
    CHK_(ptr);
    switch (tag >> 3) {
      // string cpu_name = 1;
      case 1:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 10)) {
          auto str = _internal_mutable_cpu_name();
          ptr = ::PROTOBUF_NAMESPACE_ID::internal::InlineGreedyStringParser(str, ptr, ctx);
          CHK_(::PROTOBUF_NAMESPACE_ID::internal::VerifyUTF8(str, "monitor.proto.CpuStat.cpu_name"));
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      // float cpu_precent = 2;
      case 2:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 21)) {
          cpu_precent_ = ::PROTOBUF_NAMESPACE_ID::internal::UnalignedLoad<float>(ptr);
          ptr += sizeof(float);
        } else goto handle_unusual;
        continue;
      // float user_precent = 3;
      case 3:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 29)) {
          user_precent_ = ::PROTOBUF_NAMESPACE_ID::internal::UnalignedLoad<float>(ptr);
          ptr += sizeof(float);
        } else goto handle_unusual;
        continue;
      // float system_precent = 5;
      case 5:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 45)) {
          system_precent_ = ::PROTOBUF_NAMESPACE_ID::internal::UnalignedLoad<float>(ptr);
          ptr += sizeof(float);
        } else goto handle_unusual;
        continue;
      // float nice_precent = 6;
      case 6:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 53)) {
          nice_precent_ = ::PROTOBUF_NAMESPACE_ID::internal::UnalignedLoad<float>(ptr);
          ptr += sizeof(float);
        } else goto handle_unusual;
        continue;
      // float idle_precent = 7;
      case 7:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 61)) {
          idle_precent_ = ::PROTOBUF_NAMESPACE_ID::internal::UnalignedLoad<float>(ptr);
          ptr += sizeof(float);
        } else goto handle_unusual;
        continue;
      // float iowait_precent = 8;
      case 8:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 69)) {
          iowait_precent_ = ::PROTOBUF_NAMESPACE_ID::internal::UnalignedLoad<float>(ptr);
          ptr += sizeof(float);
        } else goto handle_unusual;
        continue;
      // float irq_precent = 9;
      case 9:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 77)) {
          irq_precent_ = ::PROTOBUF_NAMESPACE_ID::internal::UnalignedLoad<float>(ptr);
          ptr += sizeof(float);
        } else goto handle_unusual;
        continue;
      // float softirp_precent = 10;
      case 10:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 85)) {
          softirp_precent_ = ::PROTOBUF_NAMESPACE_ID::internal::UnalignedLoad<float>(ptr);
          ptr += sizeof(float);
        } else goto handle_unusual;
        continue;
      default: {
      handle_unusual:
        if ((tag & 7) == 4 || tag == 0) {
          ctx->SetLastTag(tag);
          goto success;
        }
        ptr = UnknownFieldParse(tag, &_internal_metadata_, ptr, ctx);
        CHK_(ptr != nullptr);
        continue;
      }
    }  // switch
  }  // while
success:
  return ptr;
failure:
  ptr = nullptr;
  goto success;
#undef CHK_
}

::PROTOBUF_NAMESPACE_ID::uint8* CpuStat::_InternalSerialize(
    ::PROTOBUF_NAMESPACE_ID::uint8* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:monitor.proto.CpuStat)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  // string cpu_name = 1;
  if (this->cpu_name().size() > 0) {
    ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::VerifyUtf8String(
      this->_internal_cpu_name().data(), static_cast<int>(this->_internal_cpu_name().length()),
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::SERIALIZE,
      "monitor.proto.CpuStat.cpu_name");
    target = stream->WriteStringMaybeAliased(
        1, this->_internal_cpu_name(), target);
  }

  // float cpu_precent = 2;
  if (!(this->cpu_precent() <= 0 && this->cpu_precent() >= 0)) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteFloatToArray(2, this->_internal_cpu_precent(), target);
  }

  // float user_precent = 3;
  if (!(this->user_precent() <= 0 && this->user_precent() >= 0)) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteFloatToArray(3, this->_internal_user_precent(), target);
  }

  // float system_precent = 5;
  if (!(this->system_precent() <= 0 && this->system_precent() >= 0)) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteFloatToArray(5, this->_internal_system_precent(), target);
  }

  // float nice_precent = 6;
  if (!(this->nice_precent() <= 0 && this->nice_precent() >= 0)) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteFloatToArray(6, this->_internal_nice_precent(), target);
  }

  // float idle_precent = 7;
  if (!(this->idle_precent() <= 0 && this->idle_precent() >= 0)) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteFloatToArray(7, this->_internal_idle_precent(), target);
  }

  // float iowait_precent = 8;
  if (!(this->iowait_precent() <= 0 && this->iowait_precent() >= 0)) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteFloatToArray(8, this->_internal_iowait_precent(), target);
  }

  // float irq_precent = 9;
  if (!(this->irq_precent() <= 0 && this->irq_precent() >= 0)) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteFloatToArray(9, this->_internal_irq_precent(), target);
  }

  // float softirp_precent = 10;
  if (!(this->softirp_precent() <= 0 && this->softirp_precent() >= 0)) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteFloatToArray(10, this->_internal_softirp_precent(), target);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormat::InternalSerializeUnknownFieldsToArray(
        _internal_metadata_.unknown_fields(), target, stream);
  }
  // @@protoc_insertion_point(serialize_to_array_end:monitor.proto.CpuStat)
  return target;
}

size_t CpuStat::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:monitor.proto.CpuStat)
  size_t total_size = 0;

  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  // string cpu_name = 1;
  if (this->cpu_name().size() > 0) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::StringSize(
        this->_internal_cpu_name());
  }

  // float cpu_precent = 2;
  if (!(this->cpu_precent() <= 0 && this->cpu_precent() >= 0)) {
    total_size += 1 + 4;
  }

  // float user_precent = 3;
  if (!(this->user_precent() <= 0 && this->user_precent() >= 0)) {
    total_size += 1 + 4;
  }

  // float system_precent = 5;
  if (!(this->system_precent() <= 0 && this->system_precent() >= 0)) {
    total_size += 1 + 4;
  }

  // float nice_precent = 6;
  if (!(this->nice_precent() <= 0 && this->nice_precent() >= 0)) {
    total_size += 1 + 4;
  }

  // float idle_precent = 7;
  if (!(this->idle_precent() <= 0 && this->idle_precent() >= 0)) {
    total_size += 1 + 4;
  }

  // float iowait_precent = 8;
  if (!(this->iowait_precent() <= 0 && this->iowait_precent() >= 0)) {
    total_size += 1 + 4;
  }

  // float irq_precent = 9;
  if (!(this->irq_precent() <= 0 && this->irq_precent() >= 0)) {
    total_size += 1 + 4;
  }

  // float softirp_precent = 10;
  if (!(this->softirp_precent() <= 0 && this->softirp_precent() >= 0)) {
    total_size += 1 + 4;
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    return ::PROTOBUF_NAMESPACE_ID::internal::ComputeUnknownFieldsSize(
        _internal_metadata_, total_size, &_cached_size_);
  }
  int cached_size = ::PROTOBUF_NAMESPACE_ID::internal::ToCachedSize(total_size);
  SetCachedSize(cached_size);
  return total_size;
}

void CpuStat::MergeFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) {
// @@protoc_insertion_point(generalized_merge_from_start:monitor.proto.CpuStat)
  GOOGLE_DCHECK_NE(&from, this);
  const CpuStat* source =
      ::PROTOBUF_NAMESPACE_ID::DynamicCastToGenerated<CpuStat>(
          &from);
  if (source == nullptr) {
  // @@protoc_insertion_point(generalized_merge_from_cast_fail:monitor.proto.CpuStat)
    ::PROTOBUF_NAMESPACE_ID::internal::ReflectionOps::Merge(from, this);
  } else {
  // @@protoc_insertion_point(generalized_merge_from_cast_success:monitor.proto.CpuStat)
    MergeFrom(*source);
  }
}

void CpuStat::MergeFrom(const CpuStat& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:monitor.proto.CpuStat)
  GOOGLE_DCHECK_NE(&from, this);
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  if (from.cpu_name().size() > 0) {

    cpu_name_.AssignWithDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), from.cpu_name_);
  }
  if (!(from.cpu_precent() <= 0 && from.cpu_precent() >= 0)) {
    _internal_set_cpu_precent(from._internal_cpu_precent());
  }
  if (!(from.user_precent() <= 0 && from.user_precent() >= 0)) {
    _internal_set_user_precent(from._internal_user_precent());
  }
  if (!(from.system_precent() <= 0 && from.system_precent() >= 0)) {
    _internal_set_system_precent(from._internal_system_precent());
  }
  if (!(from.nice_precent() <= 0 && from.nice_precent() >= 0)) {
    _internal_set_nice_precent(from._internal_nice_precent());
  }
  if (!(from.idle_precent() <= 0 && from.idle_precent() >= 0)) {
    _internal_set_idle_precent(from._internal_idle_precent());
  }
  if (!(from.iowait_precent() <= 0 && from.iowait_precent() >= 0)) {
    _internal_set_iowait_precent(from._internal_iowait_precent());
  }
  if (!(from.irq_precent() <= 0 && from.irq_precent() >= 0)) {
    _internal_set_irq_precent(from._internal_irq_precent());
  }
  if (!(from.softirp_precent() <= 0 && from.softirp_precent() >= 0)) {
    _internal_set_softirp_precent(from._internal_softirp_precent());
  }
}

void CpuStat::CopyFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) {
// @@protoc_insertion_point(generalized_copy_from_start:monitor.proto.CpuStat)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void CpuStat::CopyFrom(const CpuStat& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:monitor.proto.CpuStat)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool CpuStat::IsInitialized() const {
  return true;
}

void CpuStat::InternalSwap(CpuStat* other) {
  using std::swap;
  _internal_metadata_.Swap(&other->_internal_metadata_);
  cpu_name_.Swap(&other->cpu_name_, &::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(),
    GetArenaNoVirtual());
  swap(cpu_precent_, other->cpu_precent_);
  swap(user_precent_, other->user_precent_);
  swap(system_precent_, other->system_precent_);
  swap(nice_precent_, other->nice_precent_);
  swap(idle_precent_, other->idle_precent_);
  swap(iowait_precent_, other->iowait_precent_);
  swap(irq_precent_, other->irq_precent_);
  swap(softirp_precent_, other->softirp_precent_);
}

::PROTOBUF_NAMESPACE_ID::Metadata CpuStat::GetMetadata() const {
  return GetMetadataStatic();
}


// @@protoc_insertion_point(namespace_scope)
}  // namespace proto
}  // namespace monitor
PROTOBUF_NAMESPACE_OPEN
template<> PROTOBUF_NOINLINE ::monitor::proto::CpuStat* Arena::CreateMaybeMessage< ::monitor::proto::CpuStat >(Arena* arena) {
  return Arena::CreateInternal< ::monitor::proto::CpuStat >(arena);
}
PROTOBUF_NAMESPACE_CLOSE

// @@protoc_insertion_point(global_scope)
#include <google/protobuf/port_undef.inc>
