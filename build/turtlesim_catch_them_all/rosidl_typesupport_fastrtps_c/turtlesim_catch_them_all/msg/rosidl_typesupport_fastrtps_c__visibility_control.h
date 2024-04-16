// generated from
// rosidl_typesupport_fastrtps_c/resource/rosidl_typesupport_fastrtps_c__visibility_control.h.in
// generated code does not contain a copyright notice

#ifndef TURTLESIM_CATCH_THEM_ALL__MSG__ROSIDL_TYPESUPPORT_FASTRTPS_C__VISIBILITY_CONTROL_H_
#define TURTLESIM_CATCH_THEM_ALL__MSG__ROSIDL_TYPESUPPORT_FASTRTPS_C__VISIBILITY_CONTROL_H_

#if __cplusplus
extern "C"
{
#endif

// This logic was borrowed (then namespaced) from the examples on the gcc wiki:
//     https://gcc.gnu.org/wiki/Visibility

#if defined _WIN32 || defined __CYGWIN__
  #ifdef __GNUC__
    #define ROSIDL_TYPESUPPORT_FASTRTPS_C_EXPORT_turtlesim_catch_them_all __attribute__ ((dllexport))
    #define ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_turtlesim_catch_them_all __attribute__ ((dllimport))
  #else
    #define ROSIDL_TYPESUPPORT_FASTRTPS_C_EXPORT_turtlesim_catch_them_all __declspec(dllexport)
    #define ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_turtlesim_catch_them_all __declspec(dllimport)
  #endif
  #ifdef ROSIDL_TYPESUPPORT_FASTRTPS_C_BUILDING_DLL_turtlesim_catch_them_all
    #define ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_turtlesim_catch_them_all ROSIDL_TYPESUPPORT_FASTRTPS_C_EXPORT_turtlesim_catch_them_all
  #else
    #define ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_turtlesim_catch_them_all ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_turtlesim_catch_them_all
  #endif
#else
  #define ROSIDL_TYPESUPPORT_FASTRTPS_C_EXPORT_turtlesim_catch_them_all __attribute__ ((visibility("default")))
  #define ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_turtlesim_catch_them_all
  #if __GNUC__ >= 4
    #define ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_turtlesim_catch_them_all __attribute__ ((visibility("default")))
  #else
    #define ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_turtlesim_catch_them_all
  #endif
#endif

#if __cplusplus
}
#endif

#endif  // TURTLESIM_CATCH_THEM_ALL__MSG__ROSIDL_TYPESUPPORT_FASTRTPS_C__VISIBILITY_CONTROL_H_
