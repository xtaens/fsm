#include "app_cfg.h"
#include "queue.h"
#include "../utilities/arm/app_type.h"
bool enqueue_byte( byte_queue_t* ptThis,uint8_t chByte)
{
    if (ptThis == NULL) {
        return false;
    }
    if (!is_byte_queue_full(ptThis)) {
        this.pchBuffer[this.hwTail] = chByte;
        this.hwTail++;
        this.hwTail = this.hwTail % this.hwSize;
        this.hwLength++;
        return true;
    }
    return false;
}

bool dequeue_byte(byte_queue_t* ptThis,uint8_t* pchByte)
{
    if (ptThis == NULL) {
        return false;
    }
    if (!is_byte_queue_empty(ptThis)) {
        *pchByte = this.pchBuffer[this.hwHead];
        this.hwHead++;
        this.hwHead = this.hwHead % this.hwSize;
        this.hwLength--;
        return true;
    }
    return false;
}

bool is_byte_queue_full(byte_queue_t* ptThis)
{
    if (ptThis != NULL) {
        if (this.hwLength >= this.hwSize) {
            return true;
        }
    }
    return false;
}

bool is_byte_queue_empty(byte_queue_t* ptThis)
{
    if (ptThis != NULL) {
        if (!this.hwLength) {
            return true;
        }
    }
    return false;
}

bool init_byte_queue(byte_queue_t* ptThis,uint8_t *pchBuffer,uint16_t hwSize)
{
    if (ptThis != NULL) {
        this.hwHead = 0;
        this.hwTail = 0;
        this.pchBuffer = pchBuffer;
        this.hwSize = hwSize;
        this.hwLength = 0;
        return true;
    }
    return false;
}