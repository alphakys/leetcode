//
// Created by alpha on 23. 10. 2.
//
//define EXPORT
//include <stdio.h>
//include <iostream>

using namespace std;

struct s{
    int id;
    int user_id;
} s;

extern "C"
{

    EXPORT
    int add_lib(int a, int b)
    {
        return a+b;
    }

    EXPORT
    void sub(int a, int b, int* ptr)
    {
        *ptr = a+b;
        printf("%d", *ptr);

    }
    EXPORT
    void get_struct(struct s* s)
    {
        cout << "id : " << s->id << " user_id : " << s->user_id;

    }


}


//// -*- coding: utf-8 -*-
////import ctypes                            파이썬 extension을 사용하기 위한 모듈
////import platform                          파이썬 아키텍처를 확인하기 위한 모듈
//
////if 'Windows' == platform.system() :      윈도우 운영체제에서 c 모듈 로드
//    path = './x64/Debug/c_module.dll'
//    c_module = ctypes.windll.LoadLibrary(path)
////elif 'Linux' == platform.system() :      리눅스 운영체제에서 c 모듈 로드
//    path = "../../leetcode/libc_module_test.so"
//    c_module = ctypes.cdll.LoadLibrary(path)
//else:
//    raise OSError()

//     EXPORT
//     void sub(int a, int b, int* ptr)
//     {
//         *ptr = a+b;
//         printf("%d", *ptr);
//
//     }

a = b'\10' * 1

print(a)

// 1. int 타입 인자를 받고, int 타입을 리턴하는 예
add = c_module.add_lib
add.argtypes = (ctypes.c_int, ctypes.c_int)
add.restype = ctypes.c_int

res = add(1, 2)
print(res)

// struct = c_module.get_struct

// sub = c_module.sub
// sub.argtypes = (ctypes.c_int, ctypes.c_int, ctypes.POINTER(ctypes.c_int))
// sub.restype = None
// outparam = ctypes.c_int()
//
// sub(3, 3, outparam)
//
// print(outparam.value)


{'id': 7841, 'user_id': 70}



{'id': 7841, 'user_id': 70, 'workout_data__repAverageWeight': [16, 16, 16, 16, 16, 16], 'machine_base_type_id': 4,
  'workout_type_id': 96, 'workout_data__workoutRep': '3', 'workout_data__weight': None,
  'workout_data__leftAvgForce': None, 'workout_data__rightAvgForce': None, 'workout_data__calories_burned': None,
  'workout_data__doneWorkoutTime': None, 'workout_data__workoutTime': '00:21', 'workout_data__workout_time': None,
  'workout_category': 'GENERAL',
  'user_id__renfit_profile_info': {'gender': 'M', 'height': 180, 'weight': 70, 'birthday': '2023-05-31',
                                   'profile_name': '박세훈입니다', 'profile_image': 'string', 'exercise_class': 'EXPERT',
                                   'exercise_amount': 1, 'rest_heart_rate': 60, 'exercise_purpose': 'WEIGHT_LOSS',
                                   'exercise_pre_risk_assessment': [
                                       {'id': 1, 'question': 'string', 'is_no_selected': False,
                                        'is_yes_selected': True}]}, 'user_id__birthday': '19930325',
  'user_id__gender': 'M', 'user_id__keypad': '9307', 'date': datetime.date(2023, 2, 21)}




//
//
// [{'id': 7841, 'user_id': 70, 'workout_data__repAverageWeight': [16, 16, 16, 16, 16, 16], 'machine_base_type_id': 4,
//   'workout_type_id': 96, 'workout_data__workoutRep': '3', 'workout_data__weight': None,
//   'workout_data__leftAvgForce': None, 'workout_data__rightAvgForce': None, 'workout_data__calories_burned': None,
//   'workout_data__doneWorkoutTime': None, 'workout_data__workoutTime': '00:21', 'workout_data__workout_time': None,
//   'workout_category': 'GENERAL',
//   'user_id__renfit_profile_info': {'gender': 'M', 'height': 180, 'weight': 70, 'birthday': '2023-05-31',
//                                    'profile_name': '박세훈입니다', 'profile_image': 'string', 'exercise_class': 'EXPERT',
//                                    'exercise_amount': 1, 'rest_heart_rate': 60, 'exercise_purpose': 'WEIGHT_LOSS',
//                                    'exercise_pre_risk_assessment': [
//                                        {'id': 1, 'question': 'string', 'is_no_selected': False,
//                                         'is_yes_selected': True}]}, 'user_id__birthday': '19930325',
//   'user_id__gender': 'M', 'user_id__keypad': '9307', 'date': datetime.date(2023, 2, 21)},
//  {'id': 7842, 'user_id': 70, 'workout_data__repAverageWeight': [5, 5], 'machine_base_type_id': 4, 'workout_type_id': 32,
//   'workout_data__workoutRep': '1', 'workout_data__weight': None, 'workout_data__leftAvgForce': None,
//   'workout_data__rightAvgForce': None, 'workout_data__calories_burned': None, 'workout_data__doneWorkoutTime': None,
//   'workout_data__workoutTime': '00:30', 'workout_data__workout_time': None, 'workout_category': 'GENERAL',
//   'user_id__renfit_profile_info': {'gender': 'M', 'height': 180, 'weight': 70, 'birthday': '2023-05-31',
//                                    'profile_name': '박세훈입니다', 'profile_image': 'string', 'exercise_class': 'EXPERT',
//                                    'exercise_amount': 1, 'rest_heart_rate': 60, 'exercise_purpose': 'WEIGHT_LOSS',
//                                    'exercise_pre_risk_assessment': [
//                                        {'id': 1, 'question': 'string', 'is_no_selected': False,
//                                         'is_yes_selected': True}]}, 'user_id__birthday': '19930325',
//   'user_id__gender': 'M', 'user_id__keypad': '9307', 'date': datetime.date(2023, 2, 21)},
//  {'id': 7843, 'user_id': 70, 'workout_data__repAverageWeight': [5, 5, 5, 5], 'machine_base_type_id': 4,
//   'workout_type_id': 93, 'workout_data__workoutRep': '2', 'workout_data__weight': None,
//   'workout_data__leftAvgForce': None, 'workout_data__rightAvgForce': None, 'workout_data__calories_burned': None,
//   'workout_data__doneWorkoutTime': None, 'workout_data__workoutTime': '00:30', 'workout_data__workout_time': None,
//   'workout_category': 'GENERAL',
//   'user_id__renfit_profile_info': {'gender': 'M', 'height': 180, 'weight': 70, 'birthday': '2023-05-31',
//                                    'profile_name': '박세훈입니다', 'profile_image': 'string', 'exercise_class': 'EXPERT',
//                                    'exercise_amount': 1, 'rest_heart_rate': 60, 'exercise_purpose': 'WEIGHT_LOSS',
//                                    'exercise_pre_risk_assessment': [
//                                        {'id': 1, 'question': 'string', 'is_no_selected': False,
//                                         'is_yes_selected': True}]}, 'user_id__birthday': '19930325',
//   'user_id__gender': 'M', 'user_id__keypad': '9307', 'date': datetime.date(2023, 2, 21)},
//  {'id': 7844, 'user_id': 70, 'workout_data__repAverageWeight': [5, 5], 'machine_base_type_id': 4, 'workout_type_id': 32,
//   'workout_data__workoutRep': '1', 'workout_data__weight': None, 'workout_data__leftAvgForce': None,
//   'workout_data__rightAvgForce': None, 'workout_data__calories_burned': None, 'workout_data__doneWorkoutTime': None,
//   'workout_data__workoutTime': '00:20', 'workout_data__workout_time': None, 'workout_category': 'GENERAL',
//   'user_id__renfit_profile_info': {'gender': 'M', 'height': 180, 'weight': 70, 'birthday': '2023-05-31',
//                                    'profile_name': '박세훈입니다', 'profile_image': 'string', 'exercise_class': 'EXPERT',
//                                    'exercise_amount': 1, 'rest_heart_rate': 60, 'exercise_purpose': 'WEIGHT_LOSS',
//                                    'exercise_pre_risk_assessment': [
//                                        {'id': 1, 'question': 'string', 'is_no_selected': False,
//                                         'is_yes_selected': True}]}, 'user_id__birthday': '19930325',
//   'user_id__gender': 'M', 'user_id__keypad': '9307', 'date': datetime.date(2023, 2, 21)},
//  {'id': 7845, 'user_id': 70, 'workout_data__repAverageWeight': [5, 5, 5, 5, 5, 5], 'machine_base_type_id': 4,
//   'workout_type_id': 87, 'workout_data__workoutRep': '3', 'workout_data__weight': None,
//   'workout_data__leftAvgForce': None, 'workout_data__rightAvgForce': None, 'workout_data__calories_burned': None,
//   'workout_data__doneWorkoutTime': None, 'workout_data__workoutTime': '00:30', 'workout_data__workout_time': None,
//   'workout_category': 'GENERAL',
//   'user_id__renfit_profile_info': {'gender': 'M', 'height': 180, 'weight': 70, 'birthday': '2023-05-31',
//                                    'profile_name': '박세훈입니다', 'profile_image': 'string', 'exercise_class': 'EXPERT',
//                                    'exercise_amount': 1, 'rest_heart_rate': 60, 'exercise_purpose': 'WEIGHT_LOSS',
//                                    'exercise_pre_risk_assessment': [
//                                        {'id': 1, 'question': 'string', 'is_no_selected': False,
//                                         'is_yes_selected': True}]}, 'user_id__birthday': '19930325',
//   'user_id__gender': 'M', 'user_id__keypad': '9307', 'date': datetime.date(2023, 2, 21)},
//  {'id': 7846, 'user_id': 70, 'workout_data__repAverageWeight': [37, 37, 5, 5, 15, 15, 15, 15, 15, 15],
//   'machine_base_type_id': 4, 'workout_type_id': 6, 'workout_data__workoutRep': '5', 'workout_data__weight': None,
//   'workout_data__leftAvgForce': None, 'workout_data__rightAvgForce': None, 'workout_data__calories_burned': None,
//   'workout_data__doneWorkoutTime': None, 'workout_data__workoutTime': '00:58', 'workout_data__workout_time': None,
//   'workout_category': 'GENERAL',
//   'user_id__renfit_profile_info': {'gender': 'M', 'height': 180, 'weight': 70, 'birthday': '2023-05-31',
//                                    'profile_name': '박세훈입니다', 'profile_image': 'string', 'exercise_class': 'EXPERT',
//                                    'exercise_amount': 1, 'rest_heart_rate': 60, 'exercise_purpose': 'WEIGHT_LOSS',
//                                    'exercise_pre_risk_assessment': [
//                                        {'id': 1, 'question': 'string', 'is_no_selected': False,
//                                         'is_yes_selected': True}]}, 'user_id__birthday': '19930325',
//   'user_id__gender': 'M', 'user_id__keypad': '9307', 'date': datetime.date(2023, 2, 21)},
//  {'id': 7848, 'user_id': 70, 'workout_data__repAverageWeight': [10, 20, 22, 46, 29, 36], 'machine_base_type_id': 4,
//   'workout_type_id': 93, 'workout_data__workoutRep': '3', 'workout_data__weight': None,
//   'workout_data__leftAvgForce': None, 'workout_data__rightAvgForce': None, 'workout_data__calories_burned': None,
//   'workout_data__doneWorkoutTime': None, 'workout_data__workoutTime': '00:40', 'workout_data__workout_time': None,
//   'workout_category': 'GENERAL',
//   'user_id__renfit_profile_info': {'gender': 'M', 'height': 180, 'weight': 70, 'birthday': '2023-05-31',
//                                    'profile_name': '박세훈입니다', 'profile_image': 'string', 'exercise_class': 'EXPERT',
//                                    'exercise_amount': 1, 'rest_heart_rate': 60, 'exercise_purpose': 'WEIGHT_LOSS',
//                                    'exercise_pre_risk_assessment': [
//                                        {'id': 1, 'question': 'string', 'is_no_selected': False,
//                                         'is_yes_selected': True}]}, 'user_id__birthday': '19930325',
//   'user_id__gender': 'M', 'user_id__keypad': '9307', 'date': datetime.date(2023, 2, 21)},
//  {'id': 7849, 'user_id': 70, 'workout_data__repAverageWeight': [18, 31, 17, 30, 17, 22], 'machine_base_type_id': 4,
//   'workout_type_id': 93, 'workout_data__workoutRep': '3', 'workout_data__weight': None,
//   'workout_data__leftAvgForce': None, 'workout_data__rightAvgForce': None, 'workout_data__calories_burned': None,
//   'workout_data__doneWorkoutTime': None, 'workout_data__workoutTime': '00:31', 'workout_data__workout_time': None,
//   'workout_category': 'GENERAL',
//   'user_id__renfit_profile_info': {'gender': 'M', 'height': 180, 'weight': 70, 'birthday': '2023-05-31',
//                                    'profile_name': '박세훈입니다', 'profile_image': 'string', 'exercise_class': 'EXPERT',
//                                    'exercise_amount': 1, 'rest_heart_rate': 60, 'exercise_purpose': 'WEIGHT_LOSS',
//                                    'exercise_pre_risk_assessment': [
//                                        {'id': 1, 'question': 'string', 'is_no_selected': False,
//                                         'is_yes_selected': True}]}, 'user_id__birthday': '19930325',
//   'user_id__gender': 'M', 'user_id__keypad': '9307', 'date': datetime.date(2023, 2, 21)},
//  {'id': 7850, 'user_id': 70, 'workout_data__repAverageWeight': [5, 5, 5, 5], 'machine_base_type_id': 4,
//   'workout_type_id': 93, 'workout_data__workoutRep': '2', 'workout_data__weight': None,
//   'workout_data__leftAvgForce': None, 'workout_data__rightAvgForce': None, 'workout_data__calories_burned': None,
//   'workout_data__doneWorkoutTime': None, 'workout_data__workoutTime': '00:22', 'workout_data__workout_time': None,
//   'workout_category': 'GENERAL',
//   'user_id__renfit_profile_info': {'gender': 'M', 'height': 180, 'weight': 70, 'birthday': '2023-05-31',
//                                    'profile_name': '박세훈입니다', 'profile_image': 'string', 'exercise_class': 'EXPERT',
//                                    'exercise_amount': 1, 'rest_heart_rate': 60, 'exercise_purpose': 'WEIGHT_LOSS',
//                                    'exercise_pre_risk_assessment': [
//                                        {'id': 1, 'question': 'string', 'is_no_selected': False,
//                                         'is_yes_selected': True}]}, 'user_id__birthday': '19930325',
//   'user_id__gender': 'M', 'user_id__keypad': '9307', 'date': datetime.date(2023, 2, 21)},
//  {'id': 7852, 'user_id': 70, 'workout_data__repAverageWeight': [36, 36, 36, 36, 36, 36], 'machine_base_type_id': 4,
//   'workout_type_id': 96, 'workout_data__workoutRep': '3', 'workout_data__weight': None,
//   'workout_data__leftAvgForce': None, 'workout_data__rightAvgForce': None, 'workout_data__calories_burned': None,
//   'workout_data__doneWorkoutTime': None, 'workout_data__workoutTime': '00:18', 'workout_data__workout_time': None,
//   'workout_category': 'GENERAL',
//   'user_id__renfit_profile_info': {'gender': 'M', 'height': 180, 'weight': 70, 'birthday': '2023-05-31',
//                                    'profile_name': '박세훈입니다', 'profile_image': 'string', 'exercise_class': 'EXPERT',
//                                    'exercise_amount': 1, 'rest_heart_rate': 60, 'exercise_purpose': 'WEIGHT_LOSS',
//                                    'exercise_pre_risk_assessment': [
//                                        {'id': 1, 'question': 'string', 'is_no_selected': False,
//                                         'is_yes_selected': True}]}, 'user_id__birthday': '19930325',
//   'user_id__gender': 'M', 'user_id__keypad': '9307', 'date': datetime.date(2023, 2, 21)}]

