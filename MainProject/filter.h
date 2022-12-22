#ifndef FILTER_H
#define FILTER_H

#include "product_catalog.h"

product_catalog** filter(product_catalog* array[], int size, bool (*check)(product_catalog* element), int& result_size);

/*
  <function_name>:
              ,
          true,
    ,

:
    array       -
    size        -
    check       -    .

                   ,
    result_data - ,    - ,



          ,
     (     true)
*/


bool check_book_subscription_by_100r(product_catalog* element);

/*
  check_book_subscription_by_author:
      - ,

:
    element -   ,


    true,           ,  false
*/


bool check_book_subscription_promtovar(product_catalog* element);

/*
  check_book_subscription_by_date:
      - ,           2021-

:
    element -   ,


    true,           2021- ,  false
*/

#endif

