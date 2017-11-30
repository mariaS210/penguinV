#include "../../src/image_function_neon.h"
#include "../../src/penguinv/cpu_identification.h"
#include "performance_test_image_function_neon.h"
#include "performance_test_helper.h"

#ifdef PENGUINV_NEON_SET
namespace
{
    std::pair < double, double > AbsoluteDifference( uint32_t size )
    {
        Performance_Test::TimerContainer timer;
    
        std::vector < Bitmap_Image::Image > image = Performance_Test::uniformImages( 3, size, size );
    
        for( uint32_t i = 0; i < Performance_Test::runCount(); ++i ) {
            timer.start();
    
            Image_Function_Neon::AbsoluteDifference( image[0], image[1], image[2] );
    
            timer.stop();
        }
    
        return timer.mean();
    }

    std::pair < double, double > BitwiseAnd( uint32_t size )
    {
        Performance_Test::TimerContainer timer;
    
        std::vector < Bitmap_Image::Image > image = Performance_Test::uniformImages( 3, size, size );
    
        for( uint32_t i = 0; i < Performance_Test::runCount(); ++i ) {
            timer.start();
    
            Image_Function_Neon::BitwiseAnd( image[0], image[1], image[2] );
    
            timer.stop();
        }
    
        return timer.mean();
    }

    std::pair < double, double > BitwiseOr( uint32_t size )
    {
        Performance_Test::TimerContainer timer;
    
        std::vector < Bitmap_Image::Image > image = Performance_Test::uniformImages( 3, size, size );
    
        for( uint32_t i = 0; i < Performance_Test::runCount(); ++i ) {
            timer.start();
    
            Image_Function_Neon::BitwiseOr( image[0], image[1], image[2] );
    
            timer.stop();
        }
    
        return timer.mean();
    }

    std::pair < double, double > BitwiseXor( uint32_t size )
    {
        Performance_Test::TimerContainer timer;
    
        std::vector < Bitmap_Image::Image > image = Performance_Test::uniformImages( 3, size, size );
    
        for( uint32_t i = 0; i < Performance_Test::runCount(); ++i ) {
            timer.start();
    
            Image_Function_Neon::BitwiseXor( image[0], image[1], image[2] );
    
            timer.stop();
        }
    
        return timer.mean();
    }

    std::pair < double, double > Invert( uint32_t size )
    {
        Performance_Test::TimerContainer timer;
    
        std::vector < Bitmap_Image::Image > image = Performance_Test::uniformImages( 2, size, size );
    
        for( uint32_t i = 0; i < Performance_Test::runCount(); ++i ) {
            timer.start();
    
            Image_Function_Neon::Invert( image[0], image[1] );
    
            timer.stop();
        }
    
        return timer.mean();
    }

    std::pair < double, double > Maximum( uint32_t size )
    {
        Performance_Test::TimerContainer timer;
    
        std::vector < Bitmap_Image::Image > image = Performance_Test::uniformImages( 3, size, size );
    
        for( uint32_t i = 0; i < Performance_Test::runCount(); ++i ) {
            timer.start();
    
            Image_Function_Neon::Maximum( image[0], image[1], image[2] );
    
            timer.stop();
        }
    
        return timer.mean();
    }

    std::pair < double, double > Minimum( uint32_t size )
    {
        Performance_Test::TimerContainer timer;
    
        std::vector < Bitmap_Image::Image > image = Performance_Test::uniformImages( 3, size, size );
    
        for( uint32_t i = 0; i < Performance_Test::runCount(); ++i ) {
            timer.start();
    
            Image_Function_Neon::Minimum( image[0], image[1], image[2] );
    
            timer.stop();
        }
    
        return timer.mean();
    }
 
    std::pair < double, double > Subtract( uint32_t size )
    {
        Performance_Test::TimerContainer timer;
    
        std::vector < Bitmap_Image::Image > image = Performance_Test::uniformImages( 3, size, size );
    
        for( uint32_t i = 0; i < Performance_Test::runCount(); ++i ) {
            timer.start();
    
            Image_Function_Neon::Subtract( image[0], image[1], image[2] );
    
            timer.stop();
        }
    
        return timer.mean();
    }

    std::pair < double, double > Threshold( uint32_t size )
    {
        Performance_Test::TimerContainer timer;
    
        std::vector < Bitmap_Image::Image > image = Performance_Test::uniformImages( 2, size, size );
        uint8_t threshold = Performance_Test::randomValue<uint8_t>( 256 );
    
        for( uint32_t i = 0; i < Performance_Test::runCount(); ++i ) {
            timer.start();
    
            Image_Function_Neon::Threshold( image[0], image[1], threshold );
    
            timer.stop();
        }
    
        return timer.mean();
    }

    std::pair < double, double > ThresholdDouble( uint32_t size )
    {
        Performance_Test::TimerContainer timer;
    
        std::vector < Bitmap_Image::Image > image = Performance_Test::uniformImages( 2, size, size );
        uint8_t minThreshold = Performance_Test::randomValue<uint8_t>( 256 );
        uint8_t maxThreshold = Performance_Test::randomValue<uint8_t>( minThreshold, 256 );
    
        for( uint32_t i = 0; i < Performance_Test::runCount(); ++i ) {
            timer.start();
    
            Image_Function_Neon::Threshold( image[0], image[1], minThreshold, maxThreshold );
    
            timer.stop();
        }
    
        return timer.mean();
    }
}
#endif

// Function naming: function_name_(image_size)
#define CONVERT_PARAMETER( parameter ) _##parameter

#define DECLARE_FUNCTION( function, size )                                        \
std::pair < double, double > CONVERT_PARAMETER(function)CONVERT_PARAMETER(size)() \
{                                                                                 \
    return function( size );                                                      \
}

#define DECLARE_FUNCTIONS( function, size1, size2, size3, size4 ) \
DECLARE_FUNCTION( function, size1 )                               \
DECLARE_FUNCTION( function, size2 )                               \
DECLARE_FUNCTION( function, size3 )                               \
DECLARE_FUNCTION( function, size4 )

#define SET_FUNCTION( function ) DECLARE_FUNCTIONS( function, 256, 512, 1024, 2048 );

#ifdef PENGUINV_NEON_SET
namespace neon
{
    SET_FUNCTION( AbsoluteDifference )
    SET_FUNCTION( BitwiseAnd         )
    SET_FUNCTION( BitwiseOr          )
    SET_FUNCTION( BitwiseXor         )
    SET_FUNCTION( Invert             )
    SET_FUNCTION( Maximum            )
    SET_FUNCTION( Minimum            )
    SET_FUNCTION( Subtract           )
    SET_FUNCTION( Threshold          )
    SET_FUNCTION( ThresholdDouble    )
}
#endif

#define ADD_FUNCTIONS( framework, function, size1, size2, size3, size4 )         \
ADD_TEST( framework, neon::CONVERT_PARAMETER(function)CONVERT_PARAMETER(size1) ); \
ADD_TEST( framework, neon::CONVERT_PARAMETER(function)CONVERT_PARAMETER(size2) ); \
ADD_TEST( framework, neon::CONVERT_PARAMETER(function)CONVERT_PARAMETER(size3) ); \
ADD_TEST( framework, neon::CONVERT_PARAMETER(function)CONVERT_PARAMETER(size4) );

#define ADD_TEST_FUNCTION( framework, function ) ADD_FUNCTIONS( framework, function, 256, 512, 1024, 2048 )

namespace Performance_Test
{
#ifdef PENGUINV_NEON_SET
    void addTests_Image_Function_Neon( PerformanceTestFramework & framework)
    {
        if( isNeonAvailable ) {
            ADD_TEST_FUNCTION( framework, AbsoluteDifference )
            ADD_TEST_FUNCTION( framework, BitwiseAnd         )
            ADD_TEST_FUNCTION( framework, BitwiseOr          )
            ADD_TEST_FUNCTION( framework, BitwiseXor         )
            ADD_TEST_FUNCTION( framework, Invert             )
            ADD_TEST_FUNCTION( framework, Maximum            )
            ADD_TEST_FUNCTION( framework, Minimum            )
            ADD_TEST_FUNCTION( framework, Subtract           )
            ADD_TEST_FUNCTION( framework, Threshold          )
            ADD_TEST_FUNCTION( framework, ThresholdDouble    )
        }
    }
#else
    void addTests_Image_Function_Neon( PerformanceTestFramework & ) {}
#endif
}