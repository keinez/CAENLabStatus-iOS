#import <Foundation/Foundation.h>

@class DZCLab;

typedef enum {
    DZCLabStatusOpen,
    DZCLabStatusClosed,
    DZCLabStatusReserved,
    DZCLabStatusReservedSoon,
    DZCLabStatusPartiallyReserved,
    DZCLabStatusCount
} DZCLabStatus;

@interface DZCDataController : NSObject

/**
 * Gets each known lab and its status, loading data from the network into
 * the cache if necessary.
 * 
 * Calls your block with a dictionary with key `DZCLab`, object `NSNumber`
 * with `int DZCLabStatus`.
 *
 * The `error` paramater to the block is nil if there was no error.
 */ 
- (void)labsAndStatusesWithBlock:(void(^)(NSDictionary *labs, NSError *error))block;

/**
 * Gets statistics about computer usage in the given lab, loading data
 * from the network into the cache if necessary.
 *
 * Calls your block with the statistics once any network activity is complete.
 * `error` will be nil if these was no error.
 */
- (void)machineCountsInLab:(DZCLab *)lab withBlock:(void(^)(NSNumber *used, NSNumber *total, DZCLab *lab, NSError *error))block;

/**
 * Make the data controller (re)load and cache all lab statuses.
 * 
 * This is intended to be used when the app launches or returns to
 * foreground to ensure we show current data.
 *
 * Your block is called when the lab statuses are ready. `error`
 * is nil if there was no error.
 */
- (void)reloadLabStatusesWithBlock:(void(^)(NSError *error))block;

/**
 * Make the data controller (re)load and cache host info for the given lab.
 * 
 * Your block is called when the host info is ready. `error`
 * is nil if there was no error.
 */
- (void)reloadHostInfoForLab:(DZCLab *)lab withBlock:(void(^)(NSError *error))block;

/**
 * Clears the cache. This affects lab status and host info.
 */
- (void)clearCache;

@end
