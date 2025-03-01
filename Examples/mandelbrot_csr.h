
/* This header file describes the CSR Slave for the mandelbrot component */

#ifndef __MANDELBROT_CSR_REGS_H__
#define __MANDELBROT_CSR_REGS_H__



/******************************************************************************/
/* Memory Map Summary                                                         */
/******************************************************************************/

/*
  Register  | Access  |   Register Contents      | Description
  Address   |         |      (64-bits)           | 
------------|---------|--------------------------|-----------------------------
        0x0 |       R |         {reserved[62:0], |     Read the busy status of
            |         |               busy[0:0]} |               the component
            |         |                          |  0 - the component is ready
            |         |                          |       to accept a new start
            |         |                          |    1 - the component cannot
            |         |                          |          accept a new start
------------|---------|--------------------------|-----------------------------
        0x8 |       W |         {reserved[62:0], |  Write 1 to signal start to
            |         |              start[0:0]} |               the component
------------|---------|--------------------------|-----------------------------
       0x10 |     R/W |         {reserved[62:0], |      0 - Disable interrupt,
            |         |   interrupt_enable[0:0]} |        1 - Enable interrupt
------------|---------|--------------------------|-----------------------------
       0x18 |  R/Wclr |         {reserved[61:0], | Signals component completion
            |         |               done[0:0], |       done is read-only and
            |         |   interrupt_status[0:0]} | interrupt_status is write 1
            |         |                          |                    to clear
------------|---------|--------------------------|-----------------------------
       0x20 |       R |         {reserved[31:0], |                 Return data
            |         |        returndata[31:0]} |                            
------------|---------|--------------------------|-----------------------------
       0x28 |     R/W |         {reserved[31:0], |              Argument real0
            |         |             real0[31:0]} |                            
------------|---------|--------------------------|-----------------------------
       0x30 |     R/W |         {reserved[31:0], |               Argument imag
            |         |              imag[31:0]} |                            
------------|---------|--------------------------|-----------------------------
       0x38 |     R/W |         {reserved[31:0], |             Argument z_real
            |         |            z_real[31:0]} |                            
------------|---------|--------------------------|-----------------------------
       0x40 |     R/W |         {reserved[31:0], |             Argument z_imag
            |         |            z_imag[31:0]} |                            

NOTE: Writes to reserved bits will be ignored and reads from reserved
      bits will return undefined values.
*/


/******************************************************************************/
/* Register Address Macros                                                    */
/******************************************************************************/

/* Byte Addresses */
#define MANDELBROT_CSR_BUSY_REG (0x0)
#define MANDELBROT_CSR_START_REG (0x8)
#define MANDELBROT_CSR_INTERRUPT_ENABLE_REG (0x10)
#define MANDELBROT_CSR_INTERRUPT_STATUS_REG (0x18)
#define MANDELBROT_CSR_RETURNDATA_REG (0x20)
#define MANDELBROT_CSR_ARG_REAL0_REG (0x28)
#define MANDELBROT_CSR_ARG_IMAG_REG (0x30)
#define MANDELBROT_CSR_ARG_Z_REAL_REG (0x38)
#define MANDELBROT_CSR_ARG_Z_IMAG_REG (0x40)

/* Argument Sizes (bytes) */
#define MANDELBROT_CSR_RETURNDATA_SIZE (4)
#define MANDELBROT_CSR_ARG_REAL0_SIZE (4)
#define MANDELBROT_CSR_ARG_IMAG_SIZE (4)
#define MANDELBROT_CSR_ARG_Z_REAL_SIZE (4)
#define MANDELBROT_CSR_ARG_Z_IMAG_SIZE (4)

/* Argument Masks */
#define MANDELBROT_CSR_RETURNDATA_MASK (0xffffffff)
#define MANDELBROT_CSR_ARG_REAL0_MASK (0xffffffff)
#define MANDELBROT_CSR_ARG_IMAG_MASK (0xffffffff)
#define MANDELBROT_CSR_ARG_Z_REAL_MASK (0xffffffff)
#define MANDELBROT_CSR_ARG_Z_IMAG_MASK (0xffffffff)

/* Status/Control Masks */
#define MANDELBROT_CSR_BUSY_MASK   (1<<0)
#define MANDELBROT_CSR_BUSY_OFFSET (0)

#define MANDELBROT_CSR_START_MASK   (1<<0)
#define MANDELBROT_CSR_START_OFFSET (0)

#define MANDELBROT_CSR_INTERRUPT_ENABLE_MASK   (1<<0)
#define MANDELBROT_CSR_INTERRUPT_ENABLE_OFFSET (0)

#define MANDELBROT_CSR_INTERRUPT_STATUS_MASK   (1<<0)
#define MANDELBROT_CSR_INTERRUPT_STATUS_OFFSET (0)
#define MANDELBROT_CSR_DONE_MASK   (1<<1)
#define MANDELBROT_CSR_DONE_OFFSET (1)


#endif /* __MANDELBROT_CSR_REGS_H__ */



