#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@class MSTokensResponse;
@class MSStorageIngestion;

typedef void (^MSGetTokenAsyncCompletionHandler)(MSTokensResponse *tokenResponses, NSError *error);

/**
 * This class retrieves and caches Cosmosdb access token.
 */
@interface MSTokenExchange : NSObject

/**
 * Get token from token exchange.
 *
 * @param httpIngestion http client.
 * @param completion callback that gets the token.
 *
 */
+ (void)performDbTokenAsyncOperationWithHttpClient:(MSStorageIngestion *)httpIngestion
           partition:(NSString *)partition
    completionHandler:(MSGetTokenAsyncCompletionHandler)completion;

+ (void)removeAllCachedTokens;

@end

NS_ASSUME_NONNULL_END
